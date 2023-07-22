void    print_bits(unsigned char octet)
{
    int i;
    unsigned int bit;

    i = 8;
    while (i--)
    {
        bit = (octec >> i & 1) + '0';
        write(1, &bit, 1);
    }
}