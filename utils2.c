/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:54:49 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/29 17:54:52 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_change_fractal(t_fractal *fractol)
{
	if (ft_strncmp(fractol->fractal_name, "Julia", 5) == 0)
	{
		fractol->fractal_name = "Mandelbrot";
		ft_initialize(fractol, fractol->argc, fractol->argv);
	}
	else if (ft_strncmp(fractol->fractal_name, "Mandelbrot", 5) == 0)
	{
		fractol->fractal_name = "Ship";
		ft_initialize(fractol, fractol->argc, fractol->argv);
	}
	else if (ft_strncmp(fractol->fractal_name, "Ship", 5) == 0)
	{
		fractol->fractal_name = "Julia";
		ft_initialize(fractol, fractol->argc, fractol->argv);
	}
}

void	ft_set_julia_random(double *cx, double *cy)
{
	*cx = ((((double)rand() / RAND_MAX) * 3.0) - 1.5);
	*cy = ((((double)rand() / RAND_MAX) * 3.0) - 1.5);
}

void	ft_reset(t_fractal *fractol)
{
	ft_initialize(fractol, fractol->argc, fractol->argv);
	if (fractol->argc == 2 && \
	ft_strncmp(fractol->fractal_name, "Julia", 5) == 0)
	{
		fractol->cx = 0.423242;
		fractol->cy = -0.204140;
	}
}

void	ft_change_iterations(t_fractal *fractol, int keycode)
{
	if (keycode == M)
	{
		if (fractol->max_iterations > 10)
			fractol->max_iterations -= 10;
	}
	else if (keycode == P)
	{
		if (fractol->max_iterations < 500)
			fractol->max_iterations += 10;
	}
}
