/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:19:55 by asalniko          #+#    #+#             */
/*   Updated: 2025/04/17 18:42:10 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static int	ft_format(va_list *ap, char c)
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
		sum += ft_puthex(va_arg(*ap, unsigned int));
	else if (c == 'X')
		sum += ft_puthexupper(va_arg(*ap, unsigned int));
	else if (c == 'p')
		sum += ft_putptr((unsigned long)va_arg(*ap, void *));
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format(&ap, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

/*int main(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int ret3 = 0;
	int ret4 = 0;
	void *a = 0;
	unsigned int b = 160;




	ret1 = printf("%p\n", a);
	ret2 = ft_printf("%p\n", a);
	ret3 = printf("%X\n", b);
	printf("printf returned hex: %d\n", ret3);
	ret3 = 0;
	ret3 = ft_printf("%X\n", b);
	ft_printf("ft_printf returned hex: %d\n", ret3);
	ret4 = ft_printf(0);

	printf("printf returned: %d\n", ret1);
	ft_printf("ft_printf returned: %d\n", ret2);
	ft_printf("ft_printf returned after 0: %d\n", ret4);
	return (0);
}*/
