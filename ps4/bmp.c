#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "bmp.h"

bool write_bmp(FILE* stream, const struct bmp_image* image);
void free_bmp_image(struct bmp_image* image);

struct bmp_header* read_bmp_header(FILE* stream);
struct pixel* read_data(FILE* stream, const struct bmp_header* header);
struct bmp_image* read_bmp(FILE* stream);


struct bmp_header* read_bmp_header(FILE* stream){
	struct bmp_header* header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	
	if (stream == NULL){
		free(header);
		return NULL;
	}

	fseek(stream,0,0);	
	fread(&header->type,sizeof(uint16_t),1,stream);

	if (header->type!=19778){
		free(header);
		return NULL;
	}

	fread(&header->size,sizeof(uint32_t),1,stream);
	fread(&header->reserved1,sizeof(uint16_t),1,stream);
	fread(&header->reserved2,sizeof(uint16_t),1,stream);
	fread(&header->offset,sizeof(uint32_t),1,stream);
	fread(&header->dib_size,sizeof(uint32_t),1,stream);
	fread(&header->width,sizeof(uint32_t),1,stream);
	fread(&header->height,sizeof(uint32_t),1,stream);
	fread(&header->planes,sizeof(uint16_t),1,stream);
	fread(&header->bpp,sizeof(uint16_t),1,stream);
	fread(&header->compression,sizeof(uint32_t),1,stream);
	fread(&header->image_size,sizeof(uint32_t),1,stream);
	fread(&header->x_ppm,sizeof(uint32_t),1,stream);
	fread(&header->y_ppm,sizeof(uint32_t),1,stream);
	fread(&header->num_colors,sizeof(uint32_t),1,stream);
	fread(&header->important_colors,sizeof(uint32_t),1,stream);

	return header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header){
	if (stream==NULL || header==NULL){
		return NULL;
	}
	int i= 0, number=0;

	struct pixel* data = (struct pixel*)calloc(sizeof(uint8_t),header->size);
	fseek(stream,header->offset,SEEK_SET);
    if ((header->height <2 && header->width%3 == 0) || (header->width%4 == 0)){
        for (i = 0; i < (header->height)*(header->width); i++){
		    fread(&data[i].blue,sizeof(uint8_t),1,stream);
		    fread(&data[i].green,sizeof(uint8_t),1,stream);
		    fread(&data[i].red,sizeof(uint8_t),1,stream);
	    }
	}
    
    number=header->offset;
    if ( ((header->width == 1) && (header->height == 1)) || ((header->width%3 == 0)&&(header->height > 1)) )
    {
        for (i = 0; i < (header->width)*(header->height); i++)
        {
            fread(&data[i].blue,sizeof(uint8_t),1,stream);
            fread(&data[i].green,sizeof(uint8_t),1,stream);
            fread(&data[i].red,sizeof(uint8_t),1,stream);
            number=number+3;
            if (((number+4)%16==0)&&(i%2!=0))
            {
                number=number+3;
                fseek(stream,3,SEEK_CUR);   
            }          
        }
    }   
    if (0 == header->width%2) {
        for (i = 0; i < (header->width) * (header->height); i++)
        {
            fread(&data[i].blue,sizeof(uint8_t),1,stream);
            fread(&data[i].green,sizeof(uint8_t),1,stream);
            number=2+number; 

            if ( ((number+4)%16 == 0) || ((number+12)%16 == 0)){
                number=number+2;
                fseek(stream,2,SEEK_CUR); 
            }      

          	number=number+1;              
            fread(&data[i].red,sizeof(uint8_t),1,stream);
            
            if ((number+12)%16 == 0 || (number+4)%16 == 0){   
                number=2 + number;
                fseek(stream,2,SEEK_CUR);
            }        
        }
    }

return  data;
}

struct bmp_image* read_bmp(FILE* stream){
	
	struct bmp_image* image=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	image->header= read_bmp_header(stream);

	if (stream==NULL){
		free(image);
		return NULL;
	}
	
	if (image->header== NULL)  {
		fprintf(stderr,"Error: This is not a BMP file.\n");
		free(image);
		return NULL;
	}

	image->data= read_data(stream,image->header);

	if (image->data==NULL){
		fprintf(stderr,"Error: Corrupted BMP file.\n");
		free(image->header);
		free(image);
		return NULL;
	}

	return image;
}


bool write_bmp(FILE* stream, const struct bmp_image* image){

	if (image==NULL || stream==NULL){
		return false;
	}

	fwrite(&image->header->type , sizeof(image->header->type) , 1, stream);
	fwrite(&image->header->size , sizeof(image->header->size) , 1, stream);
	fwrite(&image->header->reserved1 , sizeof(image->header->reserved1) , 1, stream);
	fwrite(&image->header->reserved2 , sizeof(image->header->reserved2) , 1, stream);
	fwrite(&image->header->offset , sizeof(image->header->offset) , 1, stream);
	fwrite(&image->header->dib_size , sizeof(image->header->dib_size) , 1, stream);
	fwrite(&image->header->width , sizeof(image->header->width) , 1, stream);
	fwrite(&image->header->height , sizeof(image->header->height) , 1, stream);
	fwrite(&image->header->planes , sizeof(image->header->planes) , 1, stream);
	fwrite(&image->header->bpp , sizeof(image->header->bpp) , 1, stream);
	fwrite(&image->header->compression , sizeof(image->header->compression) , 1, stream);
	fwrite(&image->header->image_size , sizeof(image->header->image_size) , 1, stream);
	fwrite(&image->header->x_ppm , sizeof(image->header->x_ppm) , 1, stream);
	fwrite(&image->header->y_ppm , sizeof(image->header->y_ppm) , 1, stream);
	fwrite(&image->header->num_colors , sizeof(image->header->num_colors) , 1, stream);
	fwrite(&image->header->important_colors , sizeof(image->header->important_colors) , 1, stream);
	
	int sum=0, i= 0, j=0, x=0;

	for (i = 0; i < image->header->height; i++){
		for ( j = 0; j < image->header->width; j++){
			fwrite(&image->data[sum].blue , sizeof(image->data[sum].blue) , 1, stream);
			fwrite(&image->data[sum].green , sizeof(image->data[sum].green) , 1, stream);
			fwrite(&image->data[sum].red , sizeof(image->data[sum].red) , 1, stream);
			sum=sum +1;
		}
		int zvysok;
		zvysok=j%4;
		char z = 0;
		if (zvysok!=0)
		{
			for (x = 0; x < zvysok; x++){
				fwrite(&z, sizeof(z) , 1, stream);
				fwrite(&z, sizeof(z) , 1, stream);
				fwrite(&z, sizeof(z) , 1, stream);
			}
		}
	}

	return true;
}


void free_bmp_image(struct bmp_image* image){
	if (image == NULL){
		return;
	}
	
	free(image->header);
	free(image->data);
	free(image);
}