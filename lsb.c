#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void lsb_decode(char *file_name, char *to_file_name);
void lsb_encode(char *file_name, char *text, char *to_file_name);
int * _get_array_bit(int byte);
int _get_last_bit(int byte);
void _print_array_bit(int *array);
void _write_file(bmp_file_info file_info, char *file_name);
int _get_int_value(int *first_bit);
void _write_text_file(int *bytes, int bytes_len, char *file_name);

void lsb_encode(char *file_name, char *text, char *to_file_name) {
    bmp_file_info file_info = load_file(file_name);
    show_file_info(file_info);
    int len = strlen(text);
    int index = file_info.data_offset;
    int *array_bit;
    for (int i = 0; i < len; i++) {
        array_bit = _get_array_bit(text[i]);
        for (int j = 0; j < 8; j++) {
            file_info.data[index] = (file_info.data[index] >> 1 << 1) + array_bit[j];
            index++;
        }
    }
    _write_file(file_info, to_file_name);
}

void lsb_decode(char *file_name, char *to_file_name) {
    bmp_file_info file_info = load_file(file_name);
    show_file_info(file_info);
    int bit_len = file_info.size - file_info.data_offset;
    int bytes_len = bit_len / 8;
    int *bits = (int*)malloc(bit_len * sizeof(int));
    int *bytes = (int*)malloc(bytes_len * sizeof(int));

    for (int i = file_info.data_offset; i < file_info.size; i++) {
        bits[i - file_info.data_offset] = _get_last_bit(file_info.data[i]);
    }
    for (int i = 0; i < bytes_len; i++) {
        bytes[i] = _get_int_value(&bits[i * 8]);
    }
    _write_text_file(bytes, bytes_len, to_file_name);
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

void _write_file(bmp_file_info file_info, char *file_name) {
    FILE *fp;
    fp = fopen(file_name, "wb+");
    for (int i = 0; i < file_info.size; i++) {
        fputc(file_info.data[i], fp);
    }
    fclose(fp);
}

void _write_text_file(int *bytes, int bytes_len, char *file_name) {
    FILE *fp;
    char character;
    fp = fopen(file_name, "wb+");
    for (int i = 0; i < bytes_len; i++) {
        character = bytes[i];
        fputc(character, fp);
    }
    fclose(fp);
}

void _print_array_bit(int *array) {
    for (int i = 0; i < 8; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int _get_int_value(int *first_bit) {
    int result = 0 + first_bit[0];
    for (int i = 1; i <= 7; i++) {
        result = result << 1;
        result += first_bit[i];
    }
    return result;
}