#!/bin/sh -x

gcc lib.s src.c -nostdlib -o ./smlc_debug -g
