/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 18:22:45 by opelman       #+#    #+#                 */
/*   Updated: 2024/08/14 13:31:57 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	ft_mlx_error(t_env *obj)
{
	if (obj->img)
		mlx_delete_image(obj->mlx, obj->img);
	if (obj->mlx)
		mlx_terminate(obj->mlx);
	exit (EXIT_FAILURE);
}

static int	ft_input_error(void)
{
	printf("\"1\" to make the Mandelbrot set\n");
	printf("\"2\" to make the Burning Ship\n");
	printf("\"3\" \"float\" \"float\" to make the Julia set\n");
	exit (0);
}

int	ft_arg_check(int argc, char **argv)
{
	if (argc == 2)
		if (ft_strncmp(argv[1], "1", ft_strlen(argv[1]) == false))
			if (ft_strncmp(argv[1], "2", ft_strlen(argv[1]) == false))
				return (ft_input_error());
	if (argc == 3 && ft_strncmp(argv[1], "3", ft_strlen(argv[1]) == true))
	{
		if (ft_isdecimal_str(argv[2]) == true && ft_isdecimal_str(argv[3]) == 0)
				return (ft_input_error());
	}
	else if (argc >= 3)
		return (ft_input_error());
	return (1);
}

void	fill_struct(t_env *obj, char **argv)
{
	obj->type = ft_atoi(argv[1]);
	obj->zoom = 1;
	obj->max_itr = MAX_ITR;
	obj->offset_re = 0;
	obj->offset_im = 0;
	if (argv[1][0] == '3')
	{
		obj->julia_re = ft_atof(argv[2]);
		obj->julia_im = ft_atof(argv[3]);
	}
	mlx_key_hook(obj->mlx, ft_complex_offset, obj);
	mlx_scroll_hook(obj->mlx, ft_mouse_scroll, obj);
	if (argv[1][0] == '1')
		mandelbrot(obj);
	else if (argv[1][0] == '2')
	{
		obj->zoom = BOAT_ZOOM;
		boat(obj);
	}
	else if (argv[1][0] == '3')
		julia(obj);
}

int	main(int argc, char *argv[])
{
	t_env		obj;
	mlx_t		mlx;
	mlx_image_t	img;

	obj.mlx = &mlx;
	obj.img = &img;
	ft_arg_check(argc, argv);
	obj.mlx = mlx_init(WIN, WIN, "FRACTOL", false);
	if (obj.mlx == NULL)
		exit(EXIT_FAILURE);
	obj.img = mlx_new_image(obj.mlx, IMG_WIDTH, IMG_LENGTH);
	if (obj.img == NULL)
		ft_mlx_error(&obj);
	mlx_set_window_pos(obj.mlx, 200, 1000);
	fill_struct(&obj, argv);
	if (mlx_image_to_window(obj.mlx, obj.img, 0, 0) == -1)
		ft_mlx_error(&obj);
	mlx_loop(obj.mlx);
	mlx_terminate(obj.mlx);
	return (0);
}
