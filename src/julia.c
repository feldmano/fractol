/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 04:59:08 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/23 12:29:08 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

static u_int32_t	ft_rgb(uint32_t iterations)
{
	int	r;
	int	g;
	int	b;

	r = (iterations * 7);
	g = (iterations * 15);
	b = (iterations * 21);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

static void	j_escape(t_env *obj, uint32_t x, uint32_t y)
{
	t_complex	c;

	c.increment = (4 / obj->zoom) / (double) WIN;
	c.re = (-2.00 + obj->offset_re) / obj->zoom + x * c.increment;
	c.im = (2 + obj->offset_im) / obj->zoom - y * c.increment;
	c.itr = 0;
	while (c.itr < obj->max_itr)
	{
		if (c.re * c.re + c.im * c.im > 4)
		{
			mlx_put_pixel(obj->img, x, y, ft_rgb(c.itr));
			return ;
		}
		c.temp = c.re * c.re - c.im * c.im;
		c.im = 2 * c.re * c.im + obj->julia_im;
		c.re = c.temp + obj->julia_re;
		c.itr++;
	}
	if (c.itr == obj->max_itr)
		mlx_put_pixel(obj->img, x, y, 0x00000FF);
}

void	julia(t_env *obj)
{
	double	x;
	double	y;

	y = -1;
	while (++y < WIN)
	{
		x = -1;
		while (++x < WIN)
			j_escape(obj, x, y);
	}
}
