/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/15 12:34:04 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/20 15:06:52 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_minus(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

int	ft_isdigit_str(const char *nptr)
{
	char	*temp;
	int		digit;

	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0')
		return (-1);
	if (temp[0] == '-' && temp[1] == '\0')
		return (free(temp), 0);
	digit = ft_skip_minus(temp);
	if (temp[digit] == '0' && temp[digit + 1] != '\0')
		return (free(temp), 0);
	while (ft_isdigit(temp[digit]) > 0)
		digit++;
	if (temp[digit] == '\0')
		return (free(temp), 1);
	return (free(temp), 0);
}

// #include <stdarg.h>
// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 	if (ft_isdigit_str(argv[1]) == 1)
// 		ft_printf("digit string\n");
// 	else
// 		ft_printf("not a digit string");
// 	return (0);
// }