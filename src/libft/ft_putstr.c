/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 16:38:09 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 11:00:51 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s)
{
	int		count;

	count = 0;
	if (s == NULL)
		return (count++, write(1, "(null)", 6));
	while (*s != '\0')
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
