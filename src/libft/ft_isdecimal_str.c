/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdecimal_str.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 21:16:21 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/23 11:13:22 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_leading_zeros(const char *nptr)
{
	int	digit;

	digit = 0;
	while (nptr[digit] == '0')
		digit++;
	return (digit);
}

int	ft_isdecimal_str(const char *nptr)
{
	char	*temp;
	char	*marker;

	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0')
		return (-1);
	marker = ft_strchr(temp, '.');
	if (marker == NULL)
		if (ft_isdigit_str(temp) == 1)
			return (free(temp), 1);
	if (marker != NULL)
		if (ft_isdigit_str(marker + 1 + ft_skip_leading_zeros(marker + 1)) != 1)
			return (free(temp), 0);
	if (marker != NULL)
		*marker = '\0';
	if (temp[0] == '-' && temp[1] == '\0')
		return (free(temp), 1);
	if (ft_isdigit_str(temp) == 0)
		return (free(temp), 0);
	free(temp);
	return (1);
}

// #include <stdarg.h>
// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 	if (ft_isdecimal_str(argv[1]) == 1)
// 		ft_printf("decimal\n");
// 	else
// 		ft_printf("not a decimal");
// 	return (0);
// }
