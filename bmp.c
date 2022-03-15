#include <stdio.h>
#include <stdlib.h>

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
void show_file_info(bmp_file_info file_info);
int _get_size_of_file(char *file_name);
int _get_data_value(int *data, int start, int end);
int _get_data_offset(int *data);
int _get_height(int *data);
int _get_width(int *data);
int _get_bit_per_pixel(int *data);
int _get_size_of_bitmap_data(int *data);

bmp_file_info load_file(char *file_name) {
	FILE *fp;
	bmp_file_info bmp_data;
	int c, data_size;
	int index = 0;
	int *data;

	fp = fopen(file_name, "rb");
	data_size = _get_size_of_file(file_name);
	data = (int*)malloc(data_size * sizeof(int));
	while ((c = fgetc(fp)) != EOF) {
		data[index] = c;
		index++;
	}
	fclose(fp);
    bmp_data.size = data_size;
    bmp_data.data = data;
    bmp_data.height = _get_height(data);
    bmp_data.width = _get_width(data);
    bmp_data.bit_per_pixel = _get_bit_per_pixel(data);
    bmp_data.data_offset = _get_data_offset(data);
    bmp_data.size_of_bitmap_data = _get_size_of_bitmap_data(data);
    bmp_data.padding_size = (bmp_data.size_of_bitmap_data - (bmp_data.height * bmp_data.width)*(bmp_data.bit_per_pixel/8)) / bmp_data.height;

    return bmp_data;
}

int _get_size_of_file(char *file_name) {
	int total;
	FILE *fp;
	fp = fopen(file_name, "rb");
	fseek(fp, 0L, SEEK_END);
	total = ftell(fp);
	fclose(fp);
	return total;
}

int _get_data_value(int *data, int start, int end) {
    int byte, result = 0;
    for (int i = start; i <= end; i++) {
        byte = data[i];
        result += byte << (i - start)*8; 
    }
    return result;
}

int _get_data_offset(int *data) {
    return _get_data_value(data, 10, 13);
}

int _get_height(int *data) {
    return _get_data_value(data, 22, 25);
}

int _get_width(int *data) {
    return _get_data_value(data, 18, 21);
}

int _get_bit_per_pixel(int *data) {
    return _get_data_value(data, 28, 29);
}

int _get_size_of_bitmap_data(int *data) {
    return _get_data_value(data, 34, 37);
}

void show_file_info(bmp_file_info file_info) {
    printf("File size: %d\n", file_info.size);
    printf("Height: %d\n", file_info.height);
    printf("Width: %d\n", file_info.width);
    printf("Bit per pixel: %d\n", file_info.bit_per_pixel);
    printf("Data Offset: %d\n", file_info.data_offset);
    printf("Size Bitmap Data: %d\n", file_info.size_of_bitmap_data);
    printf("Padding Size: %d\n", file_info.padding_size);
};