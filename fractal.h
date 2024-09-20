/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 18:32:57 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/14 13:12:26 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "src/libft/libft.h"
# include <stdio.h> //printf
# include <stdlib.h> //exit
# include <math.h>

# define IMG_WIDTH 1600
# define IMG_LENGTH 1600
# define MAX_ITR 50
# define INITIAL_ZOOM 1
# define BOAT_ZOOM 33
# define WIN 800

typedef struct s_iterator_data
{
	int		itr;
	float	re;
	float	im;
	float	temp;
	float	abs;
	float	ceiling;
}	t_itr_data;

typedef struct s_complex_plain
{
	int			itr;
	int			max_itr;
	int			pixel_x;
	int			pixel_y;
	int			rgb;
	float		re;
	float		im;
	float		zoom;
	float		increment;
	float		update_re;
	float		update_im;
	float		offset_re;
	float		offset_im;
	float		temp;
}	t_complex;

typedef struct s_environment
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				max_itr;
	int				type;
	float			zoom;
	float			offset_re;
	float			offset_im;
	float			julia_re;
	float			julia_im;

}	t_env;

//initialisations
void	fill_struct(t_env *obj, char **argv);
int		ft_mlx_error(t_env *obj);
int		ft_arg_check(int argc, char **argv);
//fractal calculations
void	mandelbrot(t_env *obj);
void	julia(t_env *obj);
void	boat(t_env *obj);

//callbacks
void	ft_complex_offset(mlx_key_data_t keydata, void *param);
void	ft_mouse_scroll(double xdelta, double ydela, void *param);

#endif
