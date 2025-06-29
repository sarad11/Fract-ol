/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:31:51 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/31 19:32:05 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_how_to_compile(void)
{
	ft_putstr("To compile: ./fractol ");
	ft_putstr("Julia | Julia Param1 Param2 | Mandelbrot | Ship");
}

void	ft_invalid_numbers_of_params(void)
{
	ft_putstr("Invalid numbers of parameters!\n");
	ft_print_how_to_compile();
}

void	ft_invalid_fractol_name(void)
{
	ft_putstr("Invalid argument!\n");
	ft_print_how_to_compile();
}

void	ft_invalid_param_values(void)
{
	ft_putstr("Param1 and Param2 values must be between -2.0 and 2.0\n");
	ft_print_how_to_compile();
}

int	ft_check_argument(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Julia", 5) != 0 \
		&& ft_strncmp(argv[1], "Mandelbrot", 10) != 0 \
		&& ft_strncmp(argv[1], "Ship", 4) != 0)
		{
			ft_invalid_fractol_name();
			return (1);
		}
	}
	else if (argc == 4 && (ft_strncmp(argv[1], "Julia", 5) == 0))
	{
		if (ft_atof(argv[2]) < -2.0 || ft_atof(argv[2]) < -2.0 \
		|| ft_atof(argv[3]) > -2.0 || ft_atof(argv[3]) > -2.0)
		{
			ft_invalid_param_values();
			return (1);
		}
	}
	return (0);
}
