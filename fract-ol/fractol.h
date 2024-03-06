/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:35:06 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/10 15:35:09 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 1000
# define HEIGHT 1000

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	int		i;
	int		stock;
	int		color;
	double	c_i;
	double	c_r;
	double	j_i;
	double	j_r;
	double	z_i;
	double	z_r;
	double	min_i;
	double	max_i;
	double	minreal;
	double	maxreal;
	int		*tab;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}			t_data;

int			handle_window_close(t_data *data);

int			mandelbrot(t_data *data);

void		msg_error(t_data *data);

void		clean_init(t_data *data);

void		init(t_data *data);

void		draw(t_data *data);

void		calculate(t_data *data);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

int			key_event(int keycode, t_data *data);

int			mouse_event(int keycode, int x, int y, t_data *data);

void		set_pixel_color(t_data *data, int x, int y, int color);

int			get_color(t_data *data);

int			julia(t_data *data);

void		clean_exit(t_data *data);

double		ft_atod(t_data *data, char *str);

int			generate_color(int res);

void		generate_color1(t_data *data, int res);

void		generate_color2(t_data *data, int res);

int			tricorn(t_data *data);

void		get_fractals(t_data *data);

#endif
