/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puti.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:53:25 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/25 17:44:52 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puti(int num)
{
	char	*base;
	int		count;

	base = "0123456789";
	count = 0;
	if (num == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	else if (num < 0)
	{
		count += write(1, "-", 1);
		num = num * -1;
	}
	while (num >= 10)
	{
		count += ft_puti(num / 10);
		num = num % 10;
	}
	count += write(1, &base[num], 1);
	return (count);
}
