/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putu.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:52:36 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 11:00:57 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putu(unsigned int num)
{
	char	*base;
	int		count;

	base = "0123456789";
	count = 0;
	while (num >= 10)
	{
		count += ft_putu(num / 10);
		num = num % 10;
	}
	count += write(1, &base[num], 1);
	return (count);
}
