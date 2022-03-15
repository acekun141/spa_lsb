#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

void lsb_decode(char *file_name);
void lsb_encode(char *file_name, char *text);

void lsb_encode(char *file_name, char *text) {
    bmp_file_info file_info = load_file(file_name);
    show_file_info(file_info);
    for (int i = file_info.data_offset; i < file_info.size; i++) {
        printf("%i: %x - %d \n", i, file_info.data[i], file_info.data[i]);
    }
};