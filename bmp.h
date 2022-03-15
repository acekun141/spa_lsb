#ifndef BMP_H
#define BMP_H

typedef struct bmp_file_info {
	int bit_per_pixel;
	int data_offset;
	int height;
	int width;
	int size;
    int size_of_bitmap_data;
    int padding_size;
	int *data;
} bmp_file_info;

bmp_file_info load_file(char *file_name);
int _get_size_of_file(char *file_name);
void show_file_info(bmp_file_info file_info);

#endif

