/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:16:43 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:44 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	find_real(int x, t_data *data)
{
	double	range;

	range = data->maxreal - data->minreal;
	return (x * (range / WIDTH) + data->minreal);
}

static double	find_imaginary(int y, t_data *data)
{
	double	range;

	range = data->max_i - data->min_i;
	return (y * (range / HEIGHT) + data->min_i);
}

static int	get_fractal(t_data *data)
{
	int	res;

	if (data->set == MANDELBROT)
		res = mandelbrot(data);
	else if (data->set == JULIA)
		res = julia(data);
	else if (data->set == TRICORN)
		res = tricorn(data);
	else
		return (0);
	return (res);
}

void	calculate(t_data *data)
{
	int	x;
	int	y;
	int	res;
	int	color;

	mlx_clear_window(data->mlx, data->win);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data->c_r = find_real(x, data);
			data->c_i = find_imaginary(y, data);
			res = get_fractal(data);
			data->stock = res;
			if (res < 100)
				color = generate_color(res);
			else
				color = data->color;
			set_pixel_color(data, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
