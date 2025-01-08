#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char   res;
    unsigned int    i;

    res = 0;
    i = 8;

    while (i--)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
    }
    return (res);

}

int main()
{

}