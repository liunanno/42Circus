#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int i;
    unsigned int bit;

    i = 0;
    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}