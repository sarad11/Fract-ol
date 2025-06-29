/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:54:56 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/21 18:56:43 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_clean(t_fractal *fractol)
{
	if (!fractol)
		return ;
	if (fractol->image)
		mlx_destroy_image(fractol->mlx, fractol->image);
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	free(fractol);
}

void	ft_render(t_fractal *fractol, char *fractol_name)
{
	if (fractol_name == NULL)
		return ;
	if (ft_strncmp(fractol_name, "Julia", 5) == 0)
	{
		fractol->fractal_name = "Julia";
		if (fractol->cx == -1.0 && fractol->cy == -1.0)
		{
			fractol->cx = 0.423242;
			fractol->cy = -0.204140;
		}
		ft_draw_julia(fractol);
	}
	else if (ft_strncmp(fractol_name, "Mandelbrot", 10) == 0)
	{
		fractol->fractal_name = "Mandelbrot";
		ft_draw_mandelbrot(fractol);
	}
	else if (ft_strncmp(fractol_name, "Ship", 10) == 0)
	{
		fractol->fractal_name = "Ship";
		ft_draw_ship(fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, \
	fractol->image, 0, 0);
}

void	ft_put_color_pixel(t_fractal *fractol, int x, int y, int color)
{
	int	*stack;

	if (fractol->img_data == NULL)
		return ;
	stack = fractol->img_data;
	stack[(y * fractol->size_line / 4) + x] = color;
}

int	ft_exit(t_fractal *fractol)
{
	ft_clean(fractol);
	exit(1);
	return (0);
}
