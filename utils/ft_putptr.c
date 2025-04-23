/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:19:06 by asalniko          #+#    #+#             */
/*   Updated: 2025/04/17 18:19:11 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		length += ft_putchar('0');
		length += ft_putchar('x');
		length += ft_putchar('0');
		return (length);
	}
	if (n >= 16)
		length += ft_putptr(n / 16);
	else
	{
		length += ft_putchar('0');
		length += ft_putchar('x');
	}
	length += ft_putchar("0123456789abcdef"[n % 16]);
	return (length);
}
