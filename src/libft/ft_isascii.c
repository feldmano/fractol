/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:50 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:56:24 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isbetween(int a, int b, int c)
{
	if (a <= c && c <= b)
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if (ft_isbetween(0, 127, c))
		return (4096);
	return (0);
}
