/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:30:22 by opelman       #+#    #+#                 */
/*   Updated: 2024/06/01 22:12:32 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	end;
	size_t	slen;

	slen = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = slen;
	while (ft_strchr(set, s1[start]) != NULL)
		start++;
	while (ft_strrchr(set, s1[end - 1]) != NULL)
		end--;
	dest = ft_substr(s1, start, end - start);
	return (dest);
}
