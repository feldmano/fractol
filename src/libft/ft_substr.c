/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 16:39:34 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:44:40 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*trim;
	size_t	slen;
	size_t	net_leng;
	size_t	net_start;

	slen = ft_strlen(s);
	net_leng = 0;
	net_start = start;
	if (start >= slen || *s == '\0' || len == 0)
		net_start = net_leng;
	else if (len > slen - net_start)
		net_leng = slen - net_start;
	else
		net_leng = len;
	trim = (char *)ft_calloc(net_leng + 1, sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s + net_start, net_leng + 1);
	return (trim);
}
