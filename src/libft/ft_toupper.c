/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:40:59 by opelman       #+#    #+#                 */
/*   Updated: 2024/02/06 18:20:35 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isbetween(int a, int b, int c)
{
	if (a <= c && c <= b)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_isbetween(97, 122, c))
		return (c - 32);
	return (c);
}
