#include "ft_printf.h"
#include <unistd.h>

int ft_puthexupper(unsigned int n)
{
	unsigned int	digit;
	int				length;

	digit = 0;
	length = 0;
	if (n / 16)
		length += ft_puthexupper(n / 16);
	digit = n % 16;
	length += write(1, &"0123456789ABCDEF"[digit], 1);
	return (length);
}