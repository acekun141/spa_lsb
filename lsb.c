#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void lsb_decode(char *file_name);
void lsb_encode(char *file_name, char *text);
int * _get_array_bit(int byte);
int _get_last_bit(int byte);
void _print_array_bit(int *array);
void _write_file(bmp_file_info file_info);

void lsb_encode(char *file_name, char *text) {
    bmp_file_info file_info = load_file(file_name);
    int len = strlen(text);
    int index = file_info.data_offset;
    int *array_bit;
    for (int i = file_info.data_offset; i < file_info.data_offset + 17*8; i++) {
        _print_array_bit(_get_array_bit(file_info.data[i]));
    }
    for (int i = 0; i < len; i++) {
        array_bit = _get_array_bit(text[i]);
        for (int j = 0; j < 8; j++) {
            file_info.data[index] = (file_info.data[index] >> 1 << 1) + array_bit[j];
            index++;
        }
    }
    printf("Result:\n");
    for (int i = file_info.data_offset; i < file_info.data_offset + 17*8; i++) {
        _print_array_bit(_get_array_bit(file_info.data[i]));
    }
    _write_file(file_info);
}

int * _get_array_bit(int byte) {
    int bit_array[8];
    int *result = (int*)malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++) {
        int bit = _get_last_bit(byte);
        bit_array[i] = bit;
        byte = byte >> 1;
    }
    for (int i = 0; i < 8; i++) {
        result[i] = bit_array[7-i];
    }
    return result;
}

int _get_last_bit(int byte) {
    int changed_last_bit = byte;
    return byte - (changed_last_bit >> 1 << 1);
}

void _write_file(bmp_file_info file_info) {
    FILE *fp;
    fp = fopen("result.bmp", "wb+");
    for (int i = 0; i < file_info.size; i++) {
        fwrite(&file_info.data[i], sizeof(int), 1, fp);
    }
    fclose(fp);
}

void _print_array_bit(int *array) {
    for (int i = 0; i < 8; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}