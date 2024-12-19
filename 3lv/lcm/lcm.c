#include <stdio.h>

// Fonction auxiliaire pour calculer le GCD (Greatest Common Divisor) avec l'algorithme d'Euclide
unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fonction pour calculer le LCM
unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b; // Éviter l'overflow en divisant avant la multiplication
}

// Fonction principale pour tester
int main(void)
{
    unsigned int a = 6;
    unsigned int b = 4;

    printf("LCM of %u and %u is: %u\n", a, b, lcm(a, b)); // Résultat attendu: 60

    a = 0;
    b = 15;

    printf("LCM of %u and %u is: %u\n", a, b, lcm(a, b)); // Résultat attendu: 0

    a = 7;
    b = 3;

    printf("LCM of %u and %u is: %u\n", a, b, lcm(a, b)); // Résultat attendu: 21

    return 0;
}
