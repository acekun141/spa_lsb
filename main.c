#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"
#include "lsb.h"

int main(int argc, char *argv[]) {
    char *option = argv[1];
    if (strcmp(option, "--encode") == 0) {
        lsb_encode(argv[2], argv[3], argv[4]);
    } else if (strcmp(option, "--decode") == 0) {
        lsb_decode(argv[2], argv[3]);
    }
	return 0;
}
