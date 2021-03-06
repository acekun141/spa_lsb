#ifndef LSB_H
#define LSB_H

void lsb_decode(char *file_name, char *to_file_name);
void lsb_encode(char *file_name, char *text, char *to_file_name);
int * _get_array_bit(int byte);
int _get_last_bit(int byte);
void _print_array_bit(int *array);
void _write_file(bmp_file_info file_info, char *file_name);

#endif
