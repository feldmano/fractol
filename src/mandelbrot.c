/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 04:59:08 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/14 13:39:53 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

static inline int	mandelbrot_iterator(int max_itr, float re, float im)
{
	t_itr_data	itr_data;

	itr_data = (t_itr_data){};
	itr_data.temp = 0;
	itr_data.itr = -1;
	while (++itr_data.itr < max_itr)
	{
		itr_data.abs = itr_data.re * itr_data.re + itr_data.im * itr_data.im;
		if (itr_data.abs > 4)
			return (itr_data.itr);
		itr_data.temp = itr_data.re * itr_data.re - itr_data.im * itr_data.im;
		itr_data.im = 2 * itr_data.re * itr_data.im + im;
		itr_data.re = itr_data.temp + re;
	}
	return (max_itr);
}

static inline void	initialize(t_env *obj, t_complex *c, mlx_image_t **img)
{
	*c = (t_complex){};
	c->max_itr = obj->max_itr;
	c->offset_re = obj->offset_re;
	c->offset_im = obj->offset_im;
	c->zoom = obj->zoom;
	c->increment = (4 / (float) WIN);
	*img = obj->img;
}

void	mandelbrot(t_env *obj)
{
	t_complex	c;
	mlx_image_t	*img;

	initialize(obj, &c, &img);
	c.pixel_y = -1;
	while (++c.pixel_y < WIN)
	{
		c.update_im = (2 + c.offset_im - c.pixel_y * c.increment ) / c.zoom;
		c.pixel_x = -1;
		while (++c.pixel_x < WIN)
		{
			c.update_re = (-2 + c.offset_re + c.pixel_x * c.increment) / c.zoom;
			c.itr = mandelbrot_iterator(c.max_itr, c.update_re, c.update_im);
			c.rgb = ((c.itr * 7 << 24) | (c.itr * 15 << 16) | \
			(c.itr * 24 << 8) | 255);
			if (c.itr < c.max_itr)
				mlx_put_pixel(img, c.pixel_x, c.pixel_y, c.rgb);
			else if (c.itr == c.max_itr)
				mlx_put_pixel(img, c.pixel_x, c.pixel_y, 0x000000FF);
		}
	}
}
