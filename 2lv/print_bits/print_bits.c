#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while (i--)
    {
        bit = (octet >> i & 1) + '0';  // Décalage à droite et récupération du bit
        write(1, &bit, 1);             
    }
}

int main()
{
    unsigned char octet1 = 5;   // 00000101
    unsigned char octet2 = 255; // 11111111
    unsigned char octet3 = 2;   // 00000010
    unsigned char octet4 = 128; // 10000000

    write(1, "Bits de 5 : ", 12);
    print_bits(octet1);
    write(1, "\n", 1);

    write(1, "Bits de 255 : ", 14);
    print_bits(octet2);
    write(1, "\n", 1);

    write(1, "Bits de 2 : ", 12);
    print_bits(octet3);
    write(1, "\n", 1);

    write(1, "Bits de 128 : ", 14);
    print_bits(octet4);
    write(1, "\n", 1);

    return 0;
}
