/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 15:22:09 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:46:22 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	net_size;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	net_size = size - 1;
	if (size == 0)
		return (slen);
	if (size > slen)
		net_size = slen;
	ft_memmove(dst, src, net_size);
	*(dst + net_size) = '\0';
	return (slen);
}
