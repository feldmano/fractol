/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:16:17 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/06 16:35:49 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	slen;
	unsigned int	i;

	slen = ft_strlen(s);
	i = 0;
	dest = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < slen)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char const src = "MAMA";
// 	char (*f) = ft_
// }
