/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:28 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/30 13:11:50 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *c)
{
	size_t	len;

	if (c == 0)
		return (0);
	len = 0;
	while (c[len] != '\0')
		len ++;
	return (len);
}
