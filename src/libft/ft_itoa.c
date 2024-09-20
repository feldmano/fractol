/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 20:22:53 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/30 13:14:12 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static long	ft_len(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_loop(char *str, long m, long i)
{
	while (m > 0 && i >= 0)
	{
		str[i - 1] = (m % 10) + 48;
		m /= 10;
		i--;
	}
}

static void	ft_negloop(char *str, long m, long i)
{
	*str = '-';
	m *= -1;
	ft_loop(str, m, i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	long	i;

	num = (long)n;
	i = ft_len(num);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		*str = 48;
	if (n > 0)
		ft_loop(str, n, i);
	if (n < 0)
		ft_negloop(str, n, i);
	return (str);
}
