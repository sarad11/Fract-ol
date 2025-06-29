/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse_events.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:48:31 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/29 11:48:37 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_random(t_fractal *fractol)
{
	if (ft_strncmp(fractol->fractal_name, "Julia", 5) == 0)
	{
		fractol->fractal_name = "Julia";
		ft_set_julia_random(&fractol->cx, &fractol->cy);
	}
}

void	ft_zoom(t_fractal *fractol, int x, int y, int sign)
{
	double	zoom_factor;

	zoom_factor = 1.25;
	if (sign == 1)
	{
		fractol->offset_x = ((x / fractol->zoom) + fractol->offset_x) \
		- (x / (fractol->zoom * zoom_factor));
		fractol->offset_y = ((y / fractol->zoom) + fractol->offset_y) \
		- (y / (fractol->zoom * zoom_factor));
		fractol->zoom *= zoom_factor;
	}
	if (sign == -1)
	{
		fractol->offset_x = ((x / fractol->zoom) + fractol->offset_x) \
		- (x / (fractol->zoom / zoom_factor));
		fractol->offset_y = ((y / fractol->zoom) + fractol->offset_y) \
		- (y / (fractol->zoom / zoom_factor));
		fractol->zoom /= zoom_factor;
	}
	else
		return ;
}

int	ft_key_hook(int key_code, t_fractal *fractol)
{
	if (key_code == ESC)
		ft_exit (fractol);
	else if (key_code == LEFT)
		fractol->offset_x -= 42 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->offset_x += 42 / fractol->zoom;
	else if (key_code == UP)
		fractol->offset_y -= 42 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->offset_y += 42 / fractol->zoom;
	else if (key_code == R)
		ft_reset(fractol);
	else if (key_code == C)
		fractol->color += 0x050505;
	else if (key_code == J)
		ft_set_random(fractol);
	else if (key_code == M || key_code == P)
		ft_change_iterations(fractol, key_code);
	else if (key_code == V)
		ft_change_fractal(fractol);
	ft_render(fractol, fractol->fractal_name);
	return (0);
}

int	ft_mouse_hook(int mouse_code, int x, int y, t_fractal *fractol)
{
	if (mouse_code == SCROLL_UP)
		ft_zoom(fractol, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		ft_zoom(fractol, x, y, -1);
	ft_render(fractol, fractol->fractal_name);
	return (0);
}
