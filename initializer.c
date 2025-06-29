/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:25:23 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/21 20:41:34 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initialize_reprint(t_fractal *fractol, int argc, char **argv)
{
	if (ft_strncmp(fractol->fractal_name, "Julia", 5) == 0 && argc == 4)
	{
		fractol->fractal_name = argv[1];
		fractol->cx = ft_atof(fractol->argv[2]);
		fractol->cy = ft_atof(fractol->argv[3]);
	}
}

void	ft_initialize(t_fractal *fractol, int argc, char **argv)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->color = 0xB366774;
	fractol->zoom = 300;
	fractol->offset_x = -2.3;
	fractol->offset_y = -2.3;
	fractol->max_iterations = 140;
	fractol->cx = -1.0;
	fractol->cy = -1.0;
	fractol->argc = argc;
	fractol->argv = argv;
	if (!fractol->fractal_name)
	{
		if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
		{
			fractol->fractal_name = argv[1];
			fractol->cx = ft_atof(fractol->argv[2]);
			fractol->cy = ft_atof(fractol->argv[3]);
		}
	}
	else
		ft_initialize_reprint(fractol, argc, argv);
}

int	ft_init_mlx(t_fractal *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		return (1);
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "mlx 42");
	if (fractol->window == NULL)
		return (1);
	fractol->image = mlx_new_image(fractol->mlx, SIZE, SIZE);
	if (fractol->image == NULL)
		return (1);
	fractol->img_data = mlx_get_data_addr(fractol->image, &fractol->bpp, \
						&fractol->size_line, \
						&fractol->endian);
	if (fractol->img_data == NULL)
		return (1);
	return (0);
}
