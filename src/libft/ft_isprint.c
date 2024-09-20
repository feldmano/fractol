/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:43 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:56:45 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isbetween(int a, int b, int c)
{
	if (a <= c && c <= b)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (ft_isbetween(32, 126, c))
		return (16384);
	return (0);
}
