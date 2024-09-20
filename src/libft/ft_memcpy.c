/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 19:25:05 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:59:00 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dest;

	if (!dest && !src)
		return (NULL);
	temp_src = src;
	temp_dest = dest;
	while (n > 0)
	{
		*temp_dest = *temp_src;
		temp_src++;
		temp_dest++;
		n--;
	}
	return (dest);
}
