/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:42:26 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/21 18:43:41 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_process(t_fractal *fractol, char *str)
{
	mlx_key_hook(fractol->window, ft_key_hook, fractol);
	mlx_mouse_hook(fractol->window, ft_mouse_hook, fractol);
	mlx_hook(fractol->window, 17, 0L, ft_exit, fractol);
	ft_render(fractol, str);
	mlx_loop(fractol->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractol;

	if (argc < 2 || argc == 3 || argc > 5)
	{
		ft_invalid_numbers_of_params();
		ft_print_how_to_compile();
	}
	else
	{
		if (ft_check_argument(argc, argv))
			return (0);
		fractol = malloc(sizeof(t_fractal));
		if (!fractol)
			return (1);
		ft_initialize(fractol, argc, argv);
		if (ft_init_mlx(fractol))
		{
			ft_clean(fractol);
			return (1);
		}
		ft_init_process(fractol, argv[1]);
		ft_clean(fractol);
	}
	return (0);
}
