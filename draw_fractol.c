/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:33:21 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/29 13:33:23 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_set_value(t_fractal *fractol)
{
	double	temp;
	int		i;

	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (i++ < fractol->max_iterations)
	{
		temp = (fractol->zx * fractol->zx) \
		- (fractol->zy * fractol->zy) + fractol->cx;
		fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = temp;
		if ((fractol->zx * fractol->zx) + \
		(fractol->zy * fractol->zy) >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		ft_put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		ft_put_color_pixel(fractol, fractol->x, fractol->y, \
		(fractol->color * (i % 255)));
}

void	ft_draw_mandelbrot(t_fractal *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			ft_mandelbrot_set_value(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	ft_julia_set_value(t_fractal *fractol)
{
	double	temp;
	int		i;

	i = 0;
	fractol->zx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->zy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (i++ < fractol->max_iterations)
	{
		temp = fractol->zx;
		fractol->zx = (fractol->zx * fractol->zx) \
		- (fractol->zy * fractol->zy) + fractol->cx;
		fractol->zy = 2 * temp * fractol->zy + fractol->cy;
		if ((fractol->zx * fractol->zx) + \
		(fractol->zy * fractol->zy) >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		ft_put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		ft_put_color_pixel(fractol, fractol->x, fractol->y, \
		(fractol->color * (i % 255)));
}

void	ft_draw_julia(t_fractal *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			ft_julia_set_value(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}
