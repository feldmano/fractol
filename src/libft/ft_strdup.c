/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 16:27:35 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:47:28 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s);
	dup = ft_calloc(slen + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, slen + 1);
	return (dup);
}
