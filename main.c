#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "lsb.h"

int main(int argc, char *argv[]) {
    lsb_encode(argv[1], argv[2], argv[3]);
	return 0;
}
