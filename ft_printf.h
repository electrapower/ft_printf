#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_start, va_arg, ...
# include <unistd.h> // write

/* ---------------	 fundamental		--------------- */
int		ft_printf(const char *format, ...);

/* ---------------	helpful		--------------- */
int     ft_putchar(char c); // %c, %% 
int 	ft_putstr(char *s); // %s
int 	ft_putnbr(int n); // %d, %i
int     ft_puthex(unsigned int n); // %x
int     ft_puthexupper(unsigned int n); // %X
int     ft_putptr(unsigned long ptr); // %p
int     ft_putunsigned(unsigned int n); // %u 

#endif