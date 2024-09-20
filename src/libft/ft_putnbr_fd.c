/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:02:56 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:52:21 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	if (num < 10)
	{
		digit = num + 48;
		write (fd, &digit, 1);
	}
}
