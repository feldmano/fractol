/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:48:23 by opelman       #+#    #+#                 */
/*   Updated: 2024/03/04 13:37:00 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (size == 0)
		return (NULL);
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (array != NULL)
		ft_bzero(array, nmemb * size);
	return (array);
}
