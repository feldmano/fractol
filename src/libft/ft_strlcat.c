/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 15:48:21 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:46:52 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	net_size;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	net_size = size;
	if (size <= dlen)
		return (slen + size);
	if (size > dlen && size <= (dlen + slen))
		net_size = size - dlen - 1;
	if (size > (dlen + slen))
		net_size = slen;
	ft_memmove(dst + dlen, src, net_size);
	*(dst + dlen + net_size) = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	
	
	char	dst2[30] = {'a', 'b', 'c'};
	char	src[30] = "abcd";
	char	dst[30] = {'a', 'b', 'c'};
	size_t 	n = 2;
	
	printf("str:%s\n", dst);printf("%zu\n", strlcat(dst, src, n));
	
	int i = 0;
	while (dst[i])
	{
		printf("%c\n", dst[i]);
		i++;
	}
	
	printf("ft_:%s\n", dst2);printf("%zu\n", ft_strlcat(dst2, src, n));
	
	i = 0;
	while (dst2[i])
	{
		printf("%c\n", dst[i]);
		i++;
	}
	return (0);
}*/