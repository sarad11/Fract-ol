/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sardomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:02:30 by sardomin          #+#    #+#             */
/*   Updated: 2025/03/21 18:03:57 by sardomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define SIZE 1500
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define R 114
# define C 99
# define H 4
# define J 106
# define P 112
# define M 109
# define V 118
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_data;
	char	*fractal_name;
	char	**argv;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		argc;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		color;
	int		max_iterations;

}			t_fractal;

// main.c
void	ft_init_process(t_fractal *fractol, char *str);
// utils.c
void	ft_putstr(char *str);
void	ft_clean(t_fractal *fractol);
void	ft_render(t_fractal *fractol, char *fractol_name);
void	ft_put_color_pixel(t_fractal *fractol, int x, int y, int color);
int		ft_exit(t_fractal *fractol);
// utils2.c
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_set_julia_random(double *cx, double *cy);
void	ft_set_mandelbrot_random(t_fractal *fractol);
void	ft_reset(t_fractal *fractol);
void	ft_change_iterations(t_fractal *fractol, int keycode);
void	ft_change_fractal(t_fractal *fractol);
// utils3.c
void	ft_print_how_to_compile(void);
void	ft_invalid_numbers_of_params(void);
void	ft_invalid_fractol_name(void);
void	ft_invalid_param_values(void);
int		ft_check_argument(int argc, char **argv);
// initialize.c
void	ft_initialize(t_fractal *fractol, int argc, char **argv);
void	ft_initialize_reprint(t_fractal *fractol, int argc, char **argv);
int		ft_init_mlx(t_fractal *fractol);
// keyboard_mouse_events.c
void	ft_zoom(t_fractal *fractol, int x, int y, int sign);
int		ft_key_hook(int key_code, t_fractal *fractol);
int		ft_mouse_hook(int mouse_code, int x, int y, t_fractal *fractol);
void	ft_set_random(t_fractal *fractol);
// draw_fractal.c
void	ft_draw_julia(t_fractal *fractol);
void	ft_julia_set_value(t_fractal *fractol);
void	ft_draw_mandelbrot(t_fractal *fractol);
void	ft_mandelbrot_set_value(t_fractal *fractol);
// draw_fractal2.c 
void	ft_ship_set_value(t_fractal *fractol);
void	ft_draw_ship(t_fractal *fractol);
// ft_atof.c
double	ft_atof(const char *str);

#endif
