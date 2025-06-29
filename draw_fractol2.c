/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:13:11 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/31 20:15:06 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ship_set_value(t_fractal *fractol)
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
		fractol->zy = fabs(2 * fractol->zx * fractol->zy) + fractol->cy;
		fractol->zx = fabs(temp);
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

void	ft_draw_ship(t_fractal *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			ft_ship_set_value(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}
