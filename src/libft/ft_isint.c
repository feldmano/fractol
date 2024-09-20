/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/09 02:55:50 by opelman       #+#    #+#                 */
/*   Updated: 2024/06/24 14:39:43 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_minus(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

int	ft_isint(const char *nptr)
{
	char	*temp;
	int		digit;

	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0')
		return (0);
	digit = ft_skip_minus(temp);
	if (temp[digit] == '0' && temp[digit + 1] != '\0')
		return (free(temp), 0);
	if (temp[0] != '0' && ft_atoi(nptr) == 0)
		return (free(temp), 0);
	while (temp[digit])
	{
		if (ft_isdigit(temp[digit]) == 0)
			return (free(temp), 0);
		digit++;
	}
	free(temp);
	return (1);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	if (ft_isint(argv[1]) == 1)
// 		printf("int\n");
// 	else
// 	printf("not\n");
// 	return (0);
// }