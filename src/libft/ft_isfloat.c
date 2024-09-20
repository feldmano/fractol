/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isfloat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 21:16:21 by opelman       #+#    #+#                 */
/*   Updated: 2024/06/01 22:45:23 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_minus(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

int	ft_isfloat(const char *nptr)
{
	char	*temp;
	int		digit;
	int		flag;

	flag = 1;
	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0')
		return (0);
	digit = ft_skip_minus(temp);
	if (*nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr) != 0 || *nptr == '.')
		nptr++;
	if (*nptr != '\0')
		flag = 0;
	if (temp[digit] == '0' && temp[digit + 1] != '\0')
		if (temp[digit + 1] != '.')
			flag = 0;
	if (ft_strchr(temp, '.') != NULL)
		if (ft_strchr(ft_strchr(temp, '.') + 1, '.') != NULL)
			flag = 0;
	free (temp);
	return (flag);
}

// #include <stdarg.h>
// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 	if (ft_isfloat(argv[1]) == 1)
// 		ft_printf("float\n");
// 	else
// 		ft_printf("not a float");
// 	return (0);
// }
