#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int n = 42;
    void *ptr = &n;

    printf("=== printf ===\n");
    printf("Hello world!\n");
    printf("Char: %c\n", 'A');
    printf("String: %s\n", "Bom dia com b de bacana");
    printf("Inteiro: %d\n", -86);
    printf("Decimal: %i\n", 344);
    printf("Unsigned: %u\n", 3535);
    printf("Hex min: %x\n", 63265719);
    printf("Hex mai: %X\n", 63265719);
    printf("Percent: %%\n");
    printf("Ponteiro: %p\n", ptr);

    ft_printf("\n=== ft_printf ===\n");
    ft_printf("Hello world!\n");
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Bom dia com b de bacana");
    ft_printf("Inteiro: %d\n", -86);
    ft_printf("Decimal: %i\n", 344);
    ft_printf("Unsigned: %u\n", 3535);
    ft_printf("Hex min: %x\n", 63265719);
    ft_printf("Hex mai: %X\n", 63265719);
    ft_printf("Percent: %%\n");
    ft_printf("Ponteiro: %p\n", ptr);

    return (0);
}