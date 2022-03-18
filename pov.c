#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

void calculate(char *file_name) {
    bmp_file_info file_info = load_file(file_name);
    int k = 127;
    int X[k+1];
    int Y[k+1];
    float Z[k+1];
    float D[k+1];
    float C = 0.0;

    // init value
    for (int i = 0; i <= k; i++) {
        X[i] = 0;
        Y[i] = 0;
        Z[i] = 0;
        D[i] = 0;
    }

    for (int i = 0; i <= k; i++) {
        for (int j = file_info.data_offset; j < file_info.size; j++) {
            if (file_info.data[j] == 2*i) {
                X[i] = X[i] + 1;
            }
            if (file_info.data[j] == 2*i + 1) {
                Y[i] = Y[i] + 1;
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (X[i] + Y[i] < 5) {
            X[i] = 0;
            Y[i] = 0;
        }
    }

    for (int i = 0; i <= k; i++) {
        Z[i] = (float) (X[i] + Y[i])/2;
    }

    for (int i = 0; i <= k; i++) {
        D[i] = (float) (X[i] - Z[i])*(X[i] - Z[i]);
    }

    for (int i = 0; i <= k; i++) {
        if (Z[i] == 0.0) {
            D[i] = 0.0;
        } else {
            D[i] = D[i]/Z[i];
        }
    }

    for (int i = 0; i <= k; i++) {
        C += D[i];
    }


    for (int i = 0; i <= k; i++) {
        // printf("X[%d] = %d\n", i, X[i]);
        // printf("Y[%d] = %d\n", i, Y[i]);
        printf("D[%d] = %.1f\n", i, D[i]);
    }
    printf("C = %.1f\n", C);

}