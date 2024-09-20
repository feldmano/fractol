/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:50 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:45:32 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*z;

	z = (char *)s + ft_strlen(s);
	while (z >= s)
	{
		if (*z == (char)c)
			return (z);
		z--;
	}
	return (NULL);
}
