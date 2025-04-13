#include "ft_printf.h"

static int  ft_format(va_list *ap, char c)
{
	int	sum;

	sum = 0;
	if (c == '%')
        sum += ft_putchar('%');
	else if (c == 'c')
		sum += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		sum += ft_putstr(va_arg(*ap, char *));
	else if ((c == 'd') || (c == 'i'))
		sum += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		sum += ft_putunsigned(va_arg(*ap, unsigned int));
    else if (c == 'x')
        sum += ft_puthex(va_arg(*ap, unsigned int), 0);
    else if (c == 'X')
        sum += ft_puthex(va_arg(*ap, unsigned int), 1);
	else if (c == 'p')
		sum += ft_putptr(va_arg(*ap, unsigned long int));
	return (sum);
}

int	ft_printf(const char *format, ...)
{
    va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format(&ap, format[i + 1]);
			i++; // skip symbol after '%'
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}