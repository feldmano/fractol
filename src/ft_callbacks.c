/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_callbacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/17 01:12:03 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/14 12:25:30 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

static void	ft_reset(t_env *obj)
{
	obj->zoom = INITIAL_ZOOM;
	if (obj->type == 2)
		obj->zoom = BOAT_ZOOM;
	obj->offset_re = 0;
	obj->offset_im = 0;
}

void	ft_complex_offset(mlx_key_data_t keydata, void *param)
{
	t_env	*obj;

	obj = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(obj->mlx);
	if (keydata.key == MLX_KEY_RIGHT)
		obj->offset_re += 0.5 / obj->zoom;
	if (keydata.key == MLX_KEY_LEFT)
		obj->offset_re -= 0.5 / obj->zoom;
	if (keydata.key == MLX_KEY_UP)
		obj->offset_im += 0.5 / obj->zoom;
	if (keydata.key == MLX_KEY_DOWN)
		obj->offset_im -= 0.5 / obj->zoom;
	if (keydata.key == MLX_KEY_R)
		ft_reset(obj);
	if (obj->type == 1)
		mandelbrot(obj);
	else if (obj->type == 2)
		boat(obj);
	else if (obj->type == 3)
		julia(obj);
}

void	ft_mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_env	*obj;

	(void)xdelta;
	obj = param;
	if (ydelta == 1)
		obj->zoom *= 1.2;
	if (ydelta == -1)
		obj->zoom *= 0.8;
	if (obj->type == 1)
		mandelbrot(obj);
	else if (obj->type == 2)
		boat(obj);
	else if (obj->type == 3)
		julia(obj);
}
