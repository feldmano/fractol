/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 23:25:02 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/20 17:36:52 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_minus(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

static double	power(int base, int exp)
{
	double	num;
	int		i;

	if (exp == '0')
		return (1);
	i = 1;
	num = base;
	while (i < exp)
	{
		num *= base;
		i++;
	}
	return (num);
}

//nptr must be either null or else only digits and decimals (no leading 0).
double	ft_atof(const char *nptr)
{
	char	*temp;
	int		digit;
	int		exp;
	double	num;

	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0' || ft_isdecimal_str(nptr) == 0)
		return (free(temp), 0);
	digit = ft_skip_minus(temp);
	num = 0;
	while (temp[digit] != '\0')
	{
		if (temp[digit] != '.')
			num = (10 * num) + (double)temp[digit] - 48;
		digit++;
	}
	if (ft_strchr(temp, '.') != NULL)
	{
		exp = &temp[ft_strlen(temp)] - ft_strchr(temp, '.') - 1;
		num = num / (power(10, exp));
	}
	if (nptr[0] == '-')
		num *= -1;
	free(temp);
	return ((double)num);
}

// #include <stdarg.h>
// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 	// float  a = 5.12345678987;
// 	// double b = 5.12345678987;
// 	// printf("[%.12f]\n", a);
// 	// printf("[%.12f]\n", b);
// 	printf("ft_atof:[%f]\n", ft_atof(argv[1]));
// 	printf("   atof:[%f]\n", atof(argv[1]));
// 	return (0);
// }