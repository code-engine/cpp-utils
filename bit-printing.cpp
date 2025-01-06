#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBitArray(char *output, int size, int limit) {
  limit -= 1;
  for(int i = limit; i >= 0; i--) {
    printf("%c", output[i]);
    if (i % 4 == 0 && i != size && i != 0) {
      printf(" ");
    }
  }

  printf("\n");
}

void printBits(int input, int limit = 32){
  int bytes = (int)sizeof(int);
  int bits = bytes * 8;
  char output[bits];
  int position = 0;
  memset(output, '0', bits);


  while(input) {
    if(input & 1) {
      output[position] = '1';
    } else {
      output[position] = '0';
    }

    position++;

    if(input >= 0) {
      input >>= 1;
    } else {
      input <<= 1;
    }
  }

  printBitArray(output, bits, limit);
}

void printBitsUnsigned(unsigned int input, int limit = 32) {
  int bytes = (int)sizeof(int);
  int bits = bytes * 8;
  char output[bits];
  int position = 0;

  memset(output, '0', bits);

  while(input) {
    if(input & 1) {
      output[position] = '1';
    } else {
      output[position] = '0';
    }

    position++;

    if(input >= 0) { input >>= 1; }
  }

  printBitArray(output, bits, limit);
}
