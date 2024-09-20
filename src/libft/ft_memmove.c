/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 20:47:39 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:59:15 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dest;
	size_t				i;

	temp_src = src;
	temp_dest = dest;
	if (src < dest)
	{
		while (n > 0)
		{
			*(temp_dest + n - 1) = *(temp_src + n - 1);
			n--;
		}
	}
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(temp_dest + i) = *(temp_src + i);
			i++;
		}
	}
	return (dest);
}
