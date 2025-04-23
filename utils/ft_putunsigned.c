/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:26:09 by asalniko          #+#    #+#             */
/*   Updated: 2025/04/14 16:26:11 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putunsigned(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
