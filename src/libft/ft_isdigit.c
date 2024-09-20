/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:47 by opelman       #+#    #+#                 */
/*   Updated: 2024/01/26 10:56:36 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isbetween(int a, int b, int c)
{
	if (a <= c && c <= b)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (ft_isbetween(48, 57, c))
		return (2048);
	return (0);
}
