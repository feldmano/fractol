/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:44 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/30 13:13:44 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sdup1;
	unsigned char	*sdup2;

	sdup1 = (unsigned char *)s1;
	sdup2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (!*sdup1 && !*sdup2)
			return (0);
		if (*sdup1 != *sdup2)
			return (*sdup1 - *sdup2);
		sdup1++;
		sdup2++;
		n--;
	}
	return (0);
}
