/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isuint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/01 21:39:18 by opelman       #+#    #+#                 */
/*   Updated: 2024/06/01 22:45:29 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_isuint(const char *nptr)
{
	int	i;

	i = 0;
	while (ft_isdigit(nptr[i]) != 0)
		i++;
	return (i);
}
