#include <stdio.h>
#include <math.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int hash(int k, int j) {
    return (k%j);
}

void main()
{
    printf("hash of %");
    for (int i = 0; i < 100; i++)
    {
        printf("\nLeading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(hash(i,8)));
    }
    
}