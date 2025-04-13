#include "ft_printf.h"
#include <unistd.h>

int	ft_putptr(unsigned long int n)
{
	int	digit;
	int	length;

	digit = 0;
	length = 0;

	if (n / 16)
		length += ft_putptr(n / 16);
	if (length == 0)
    {
        length += ft_putchar('0');
	    length += ft_putchar('x');
    }
	digit = n % 16;
	length += write(1, &"0123456789abcdef"[digit], 1);
	return (length);
}