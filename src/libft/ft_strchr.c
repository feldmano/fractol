/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:28 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/15 15:09:05 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	if (s == NULL)
		return (NULL);
	a = (char *)s;
	if ((char) c == '\0')
		return (a + ft_strlen(s));
	while (*a != '\0')
	{
		if (*a == (char) c)
			return (a);
		a++;
	}
	return (NULL);
}
