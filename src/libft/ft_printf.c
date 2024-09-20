/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 10:07:32 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:48:32 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	ft_percent(char *src, va_list in)
{
	char	*index;

	index = src + 1;
	if (*index == '\0')
		return (0);
	if (*index == '%')
		return (write(1, "%", 1));
	if (*index == 'c')
		return (ft_putchr(va_arg(in, int)));
	if (*index == 's')
		return (ft_putstr(va_arg(in, char *)));
	if (*index == 'd' || *index == 'i')
		return (ft_puti(va_arg(in, int)));
	if (*index == 'u')
		return (ft_putu(va_arg(in, unsigned int)));
	if (*index == 'x')
		return (ft_puthex(va_arg(in, unsigned)));
	if (*index == 'X')
		return (ft_puthex_cap(va_arg(in, unsigned)));
	if (*index == 'p')
		return (ft_putptr(va_arg(in, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	arg;

	if (s == NULL)
		return (-1);
	va_start(arg, s);
	count = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			count += ft_percent((char *)s, arg);
			if (count < 0)
				return (-1);
			s++;
			if (*s == '\0')
				break ;
		}
		else
			count += write(1, (char *)s, 1);
		s++;
	}
	va_end(arg);
	return (count);
}
