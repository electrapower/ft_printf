#include "ft_printf.h"
#include <unistd.h>

int ft_puthex(unsigned int n, int uppercase)
{
    int i;
    char *base;

    if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	i = 0;
    if (n >= 16)
		i += ft_puthex(n / 16, uppercase);
	i += ft_putchar(base[n % 16]);

	return (i);
}