/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 12:24:32 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/18 15:46:29 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_minus(const char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

//nptr must be either null or else only digits (no decimals/ no leading 0).
int	ft_atoi(const char *nptr)
{
	char	*temp;
	long	num;
	int		digit;

	temp = ft_strtrim(nptr, " ");
	if (temp == NULL || temp[0] == '\0' || ft_isdigit_str(nptr) == 0)
		return (0);
	digit = ft_skip_minus(temp);
	num = 0;
	while (temp[digit] != '\0')
	{
		num = (10 * num) + (long) temp[digit] - 48;
		digit++;
	}
	if (temp[0] == '-')
	{
		num *= -1;
		if (num < -2147483648)
			return (free(temp), 0);
	}
	else if (num > 2147483647)
		return (free(temp), 0);
	return (free(temp), (int) num);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	(void) argc;
// 	printf("[%d]", ft_atoi(argv[1]));
// 	return (0);
// }
