#!/bin/bash

gcc -Wall -c bmp.c
gcc -Wall -c lsb.c
gcc -Wall -c pov.c
gcc -Wall -c main.c
gcc -o program main.o pov.o lsb.o bmp.o
