#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image);
struct bmp_image* flip_vertically(const struct bmp_image* image);
struct bmp_image* rotate_right(const struct bmp_image* image);
struct bmp_image* rotate_left(const struct bmp_image* image);
struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep);
struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width);
struct bmp_image* scale(const struct bmp_image* image, float factor);

struct bmp_image* flip_horizontally(const struct bmp_image* image){

	if (image==NULL){
		return NULL;
	}

	struct bmp_image* horizontally=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	horizontally->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	horizontally->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);


	int pole[image->header->height][image->header->width];
	int mark=0;
	int i=0, j=0;

	for (i = 0; i < image->header->height; i++){
		for (j = 0; j < image->header->width; j++){
			pole[i][j]= mark;
			mark=mark + 1;
		}
	}

	mark=0;
	for (i = 0; i < image->header->height; i++){
		for (j = image->header->width-1; j >= 0; j--){
			horizontally->data[mark]=image->data[pole[i][j]];
			mark= mark + 1;
		}
	}

	horizontally->header->type=image->header->type;
	horizontally->header->size=image->header->size;
	horizontally->header->reserved1=image->header->reserved1;
	horizontally->header->reserved2=image->header->reserved2;
	horizontally->header->offset=image->header->offset;
	horizontally->header->dib_size=image->header->dib_size;
	horizontally->header->width=image->header->width;
	horizontally->header->height=image->header->height;
	horizontally->header->planes=image->header->planes;
	horizontally->header->bpp=image->header->bpp;
	horizontally->header->compression=image->header->compression;
	horizontally->header->image_size=image->header->image_size;
	horizontally->header->x_ppm=image->header->x_ppm;
	horizontally->header->y_ppm=image->header->y_ppm;
	horizontally->header->num_colors=image->header->num_colors;
	horizontally->header->important_colors=image->header->important_colors;	

	return horizontally;
}

struct bmp_image* flip_vertically(const struct bmp_image* image){

	if (image==NULL){
		return NULL;
	}
	struct bmp_image* vertically=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	vertically->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	vertically->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	vertically->header->type=image->header->type;
	vertically->header->size=image->header->size;
	vertically->header->reserved1=image->header->reserved1;
	vertically->header->reserved2=image->header->reserved2;
	vertically->header->offset=image->header->offset;
	vertically->header->dib_size=image->header->dib_size;
	vertically->header->width=image->header->width;
	vertically->header->height=image->header->height;
	vertically->header->planes=image->header->planes;
	vertically->header->bpp=image->header->bpp;
	vertically->header->compression=image->header->compression;
	vertically->header->image_size=image->header->image_size;
	vertically->header->x_ppm=image->header->x_ppm;
	vertically->header->y_ppm=image->header->y_ppm;
	vertically->header->num_colors=image->header->num_colors;
	vertically->header->important_colors=image->header->important_colors;


 	int pole[image->header->height][image->header->width];
	int mark=0, i=0, j=0;

	for (i = 0; i < image->header->height; i++){
		for (j = 0; j < image->header->width; j++){
			pole[i][j]=mark;
			mark=mark + 1;
		}
	}

	mark=0;
	for (i = image->header->height-1; i >= 0; i--){
		for (j = 0; j < image->header->width; j++){
			vertically->data[mark]=image->data[pole[i][j]];
			mark= mark + 1;
		}
	}

	return vertically;
}

struct bmp_image* rotate_right(const struct bmp_image* image){
	if (image==NULL){
		return NULL;
	}

	struct bmp_image* right=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	right->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	right->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	right->header->type=image->header->type;
	right->header->size=image->header->size;
	right->header->reserved1=image->header->reserved1;
	right->header->reserved2=image->header->reserved2;
	right->header->offset=image->header->offset;
	right->header->dib_size=image->header->dib_size;
	right->header->width=image->header->width;
	right->header->height=image->header->height;
	right->header->planes=image->header->planes;
	right->header->bpp=image->header->bpp;
	right->header->compression=image->header->compression;
	right->header->image_size=image->header->image_size;
	right->header->x_ppm=image->header->x_ppm;
	right->header->y_ppm=image->header->y_ppm;
	right->header->num_colors=image->header->num_colors;
	right->header->important_colors=image->header->important_colors;
    

	int i=0, j=0, a=0, b=0;
   for (i = 0;  i< image->header->height; i++)
        {
            for (j = 0; j < image->header->width; j++){
            	a=image->header->height-1;
				b=image->header->width-1;
                right->data[j * image->header->height + image->header->height - i - 1] = image->data[(b-j) + (a-i) * image->header->width];
            }
        }
    uint32_t pozicia;
	pozicia=right->header->width;
	right->header->width=right->header->height;
	right->header->height=pozicia;
	
	if (right->header->width%4 == 3){
		right->header->size= 0;
		right->header->image_size= 0;
		for (i = 0; i < right->header->height; i++)
		{
			right->header->image_size=right->header->image_size+((right->header->width*3)+3);
		}
		
		right->header->size=right->header->image_size+54;
	}
	if (right->header->width%4 == 2){
		right->header->size= 0;
		right->header->image_size= 0;

		for (i = 0; i < right->header->height; i ++)
			right->header->image_size=right->header->image_size+((right->header->width*3)+2);
		
		right->header->size=right->header->image_size + 54;
	}
	if (right->header->width%4 == 1){
		right->header->size=0;
		right->header->image_size= 0;
		for (i = 0; i < right->header->height; i++)
			right->header->image_size=right->header->image_size+((right->header->width*3)+1);
		
		right->header->size=right->header->image_size + 54;
	}

	if (0 == right->header->width%4){
		right->header->size=0;
		right->header->image_size=0;
		for (i = 0; i < right->header->height; i++)
			right->header->image_size=right->header->image_size+((right->header->width*3));

		right->header->size=right->header->image_size+54;
	}

	return right;
}

struct bmp_image* rotate_left(const struct bmp_image* image){
	if (NULL == image){
		return NULL;
	}
	struct bmp_image* left=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	left->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	left->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	left->header->type=image->header->type;
	left->header->size=image->header->size;
	left->header->reserved1=image->header->reserved1;
	left->header->reserved2=image->header->reserved2;
	left->header->offset=image->header->offset;
	left->header->dib_size=image->header->dib_size;
	left->header->width=image->header->width;
	left->header->height=image->header->height;
	left->header->planes=image->header->planes;
	left->header->bpp=image->header->bpp;
	left->header->compression=image->header->compression;
	left->header->image_size=image->header->image_size;
	left->header->x_ppm=image->header->x_ppm;
	left->header->y_ppm=image->header->y_ppm;
	left->header->num_colors=image->header->num_colors;
	left->header->important_colors=image->header->important_colors;

	int y=0, x=0, i=0;
	for (y = 0; y < image->header->height; y++)
            for (x = 0; x < image->header->width; x++)
                left->data[x * image->header->height + image->header->height - y - 1] = image->data[x + y * image->header->width];

    uint32_t otoc;
	otoc=left->header->width;
	left->header->width=left->header->height;
	left->header->height=otoc;

	if (left->header->width%4==3){
		left->header->size=0;
		left->header->image_size=0;
		for (i = 0; i < left->header->height; i++)
			left->header->image_size=left->header->image_size+((left->header->width*3) + 3);

		left->header->size=left->header->image_size + 54;
	}
	if (left->header->width%4==2)
	{
		left->header->size=0;
		left->header->image_size=0;
		for (i = 0; i < left->header->height; i++)
			left->header->image_size=left->header->image_size+((left->header->width*3)+2);

		left->header->size=left->header->image_size+54;
	}
	if (left->header->width%4 == 1)
	{
		left->header->size=0;
		left->header->image_size = 0;
		for (i = 0; i < left->header->height; i++)
			left->header->image_size=left->header->image_size+((left->header->width*3)+1);
		
		left->header->size=left->header->image_size+54;
	}

	if (left->header->width%4 == 0)
	{
		left->header->size=0;
		left->header->image_size=0;
		for (i = 0; i < left->header->height; ++i)
			left->header->image_size=left->header->image_size+((left->header->width*3));
	
		left->header->size=left->header->image_size+54;
	}

	return left;
}


struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep){

	if (image==NULL)
	{
		return NULL;
	}
	if (colors_to_keep == NULL)
	{
		return NULL;
	}

	
	if (*colors_to_keep!='r' && *colors_to_keep!='g' && *colors_to_keep!='b')
	{
		return NULL;
	}

	struct bmp_image* farba=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	farba->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	farba->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	farba->header->type=image->header->type;
	farba->header->size=image->header->size;
	farba->header->reserved1=image->header->reserved1;
	farba->header->reserved2=image->header->reserved2;
	farba->header->offset=image->header->offset;
	farba->header->dib_size=image->header->dib_size;
	farba->header->width=image->header->width;
	farba->header->height=image->header->height;
	farba->header->planes=image->header->planes;
	farba->header->bpp=image->header->bpp;
	farba->header->compression=image->header->compression;
	farba->header->image_size=image->header->image_size;
	farba->header->x_ppm=image->header->x_ppm;
	farba->header->y_ppm=image->header->y_ppm;
	farba->header->num_colors=image->header->num_colors;
	farba->header->important_colors=image->header->important_colors;

	int help=0, i=0, j=0, r=0;
	for (i = 0; i < image->header->width; i++)
	
		for (j = 0; j < image->header->height; j++)
		{
			for (r = 0; r < strlen(colors_to_keep); r++)
			{
				if (colors_to_keep[r] == 'g')
					farba->data[help].green	= image->data[help].green;
				if (colors_to_keep[r] == 'b')
					farba->data[help].blue = image->data[help].blue;
				if (colors_to_keep[r]  == 'r')
					farba->data[help].red = image->data[help].red;
			}
			help= help + 1;
		}
	
	return farba;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width){

	if (image == NULL)
		return NULL;
	
	if (height < 0 || width < 0 || height>image->header->height ||  width>image->header->width)
		return NULL;
	
	if (start_y>image->header->height || start_x>image->header->width)
		return NULL;

	struct bmp_image* skrob=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	skrob->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	skrob->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	skrob->header->type=image->header->type;
	skrob->header->size=image->header->size;
	skrob->header->reserved1=image->header->reserved1;
	skrob->header->reserved2=image->header->reserved2;
	skrob->header->offset=image->header->offset;
	skrob->header->dib_size=image->header->dib_size;
	skrob->header->width=image->header->width;
	skrob->header->height=image->header->height;
	skrob->header->planes=image->header->planes;
	skrob->header->bpp=image->header->bpp;
	skrob->header->compression=image->header->compression;
	skrob->header->image_size=image->header->image_size;
	skrob->header->x_ppm=image->header->x_ppm;
	skrob->header->y_ppm=image->header->y_ppm;
	skrob->header->num_colors=image->header->num_colors;
	skrob->header->important_colors=image->header->important_colors;

	return skrob;
}

struct bmp_image* scale(const struct bmp_image* image, float factor){

	if (image == NULL)
		return NULL;
	
	if (factor < 0)
		return NULL;
	

	struct bmp_image* scala=(struct bmp_image*)calloc(sizeof(int),sizeof(struct bmp_image));
	scala->header = (struct bmp_header*)calloc(sizeof(int),sizeof(struct bmp_header));
	scala->data = (struct pixel*)calloc(sizeof(uint8_t),image->header->size);

	scala->header->type=image->header->type;
	scala->header->size=image->header->size;
	scala->header->reserved1=image->header->reserved1;
	scala->header->reserved2=image->header->reserved2;
	scala->header->offset=image->header->offset;
	scala->header->dib_size=image->header->dib_size;
	scala->header->width=image->header->width;
	scala->header->height=image->header->height;
	scala->header->planes=image->header->planes;
	scala->header->bpp=image->header->bpp;
	scala->header->compression=image->header->compression;
	scala->header->image_size=image->header->image_size;
	scala->header->x_ppm=image->header->x_ppm;
	scala->header->y_ppm=image->header->y_ppm;
	scala->header->num_colors=image->header->num_colors;
	scala->header->important_colors=image->header->important_colors;

	return scala;
}
