#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#include "bmp.h"
#include "transformations.h"

int main(int argc, char const *argv[])
{
	int i= 0;
	int correct= 0;
	for (i = 0; i < argc; i++)
			printf("%s",argv[i] );
			
		printf("\n");

	struct bmp_image *image;
	FILE *stream;
	FILE* novi = fopen("testnovi2.bmp", "wb");
	stream=fopen("square.2x4.bmp", "rb");

	image=read_bmp(stream);

	printf("type= %d \n",image->header->type);
	printf("size= %d \n",image->header->size);
	printf("reserved1= %d \n",image->header->reserved1);
	printf("reserved2= %d \n",image->header->reserved2);
	printf("offset= %d \n",image->header->offset);
	printf("dib_size= %d \n",image->header->dib_size);
	printf("width= %d \n",image->header->width);
	printf("height= %d \n",image->header->height);
	printf("planes= %d \n",image->header->planes);
	printf("bpp= %d \n",image->header->bpp);
	printf("compression= %d \n",image->header->compression);
	printf("image_size= %d \n",image->header->image_size);
	printf("x_ppm= %d \n",image->header->x_ppm);
	printf("y_ppm= %d \n",image->header->y_ppm);
	printf("num_colors= %d \n",image->header->num_colors);
	printf("important_colors= %d \n",image->header->important_colors);
	printf("\n\n");

	printf("blue= %d \n",image->data[0].blue);
	printf("green= %d \n",image->data[0].green);
	printf("red= %d \n",image->data[0].red);

	flip_horizontally(image);
	flip_vertically(image);
	printf("flip_vertically\n");
	rotate_right(image); 
	rotate_left(image);
	char colors_to_keep[]="rg";
	
	correct =write_bmp(novi,flip_horizontally(image));
	printf("correct= %d\n", correct);
	extract( image, colors_to_keep);
	crop(image, image->header->width, image->header->width, image->header->width, image->header->width);
	scale(image, 1);
	fclose(novi);
	fclose(stream);


	free_bmp_image(image);
	return 0;
}
