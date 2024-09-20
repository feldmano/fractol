/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:54 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:56:12 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isbetween(int a, int b, int c)
{
	if (a <= c && c <= b)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isbetween(65, 90, c) || ft_isbetween(97, 122, c))
		return (1024);
	return (0);
}
