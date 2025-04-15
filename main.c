#include "ft_printf.h"
#include <stdio.h>   // for usual printf
#include <limits.h>

int main(void)
{
    char	*str = "world";
	int		number = -42;
	unsigned int u = UINT_MAX;
	void	*ptr = str;

	int ret1, ret2;

	printf("\n🔵 ORIG printf:\n");
	ret1 = printf("char: %c | str: %s | int: %d | i: %i | uint: %u | hex: %x | HEX: %X | ptr: %p | %%\n",
		'A', str, number, number, u, 255, 255, ptr);
	printf("return: %d\n", ret1);

	printf("\n🟣 FT_PRINTF:\n");
	ret2 = ft_printf("char: %c | str: %s | int: %d | i: %i | uint: %u | hex: %x | HEX: %X | ptr: %p | %%\n",
		'A', str, number, number, u, 255, 255, ptr);
	printf("return: %d\n", ret2);

	return (0);
}