/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   boat.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/30 19:56:38 by opelman       #+#    #+#                 */
/*   Updated: 2024/07/30 22:25:22 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

static inline int	boat_iterator(int max_itr, float re, float im)
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
		itr_data.temp = -1 * (itr_data.re * itr_data.re - \
		itr_data.im * itr_data.im) + re;
		itr_data.im = -2 * fabs(itr_data.re * itr_data.im) + im;
		itr_data.re = itr_data.temp;
	}
	return (max_itr);
}

static inline void	initialize(t_env *obj, t_complex *c, mlx_image_t **img)
{
	*c = (t_complex){};
	c->max_itr = 25;
	c->offset_re = obj->offset_re;
	c->offset_im = obj->offset_im;
	c->zoom = obj->zoom;
	c->increment = (4 / c->zoom) / (float) WIN;
	*img = obj->img;
}

void	boat(t_env *obj)
{
	t_complex	c;
	mlx_image_t	*img;

	initialize(obj, &c, &img);
	c.pixel_y = -1;
	while (++c.pixel_y < WIN)
	{
		c.update_im = (3.5 + c.offset_im) / c.zoom - c.pixel_y * c.increment;
		c.pixel_x = -1;
		while (++c.pixel_x < WIN)
		{
			c.update_re = (56 + c.offset_re) / c.zoom + \
			c.pixel_x * c.increment;
			c.itr = boat_iterator(c.max_itr, c.update_re, c.update_im);
			c.rgb = ((c.itr * 251 << 24) | (c.itr * 110 << 16) | \
			(c.itr * 55 << 8) | 255);
			if ((c.update_im <= 0 || c.update_im > 0) && c.itr < 15)
				mlx_put_pixel(img, c.pixel_x, c.pixel_y, 0x87CEFAAA);
			else if (c.itr == c.max_itr || c.itr < 4)
				mlx_put_pixel(img, c.pixel_x, c.pixel_y, 0x00000FF);
			else
				mlx_put_pixel(img, c.pixel_x, c.pixel_y, c.rgb);
		}
	}
}
