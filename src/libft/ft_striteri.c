/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:17:09 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/02 10:47:14 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			slen;
	unsigned int	i;

	slen = ft_strlen(s);
	i = 0;
	while (i < slen)
	{
		f(i, &s[i]);
		i++;
	}
}
