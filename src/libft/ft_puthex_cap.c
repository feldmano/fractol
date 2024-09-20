/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_cap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 16:00:01 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/27 20:01:17 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex_cap(unsigned long int num)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	while (num >= 16)
	{
		count += ft_puthex_cap(num / 16);
		num = num % 16;
	}
	count += write(1, &base[num], 1);
	return (count);
}
