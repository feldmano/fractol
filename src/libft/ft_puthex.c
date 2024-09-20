/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:52:13 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 11:00:21 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex(unsigned long int num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	while (num >= 16)
	{
		count += ft_puthex(num / 16);
		num = num % 16;
	}
	count += write(1, &base[num], 1);
	return (count);
}
