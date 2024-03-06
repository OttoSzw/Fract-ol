/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:55 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:56 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	zoom(t_data *data, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = data->minreal - data->maxreal;
	center_i = data->max_i - data->min_i;
	data->maxreal = data->maxreal + (center_r - zoom * center_r) / 2;
	data->minreal = data->maxreal + zoom * center_r;
	data->min_i = data->min_i + (center_i - zoom * center_i) / 2;
	data->max_i = data->min_i + zoom * center_i;
}

static void	move(t_data *data, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = data->maxreal - data->minreal;
	center_i = data->max_i - data->min_i;
	if (direction == 'R')
	{
		data->minreal += center_r * distance;
		data->maxreal += center_r * distance;
	}
	else if (direction == 'L')
	{
		data->minreal -= center_r * distance;
		data->maxreal -= center_r * distance;
	}
	else if (direction == 'U')
	{
		data->min_i -= center_i * distance;
		data->max_i -= center_i * distance;
	}
	else if (direction == 'D')
	{
		data->min_i += center_i * distance;
		data->max_i += center_i * distance;
	}
}

int	handle_window_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keycode == 61)
		zoom(data, 0.5);
	else if (keycode == 45)
		zoom(data, 2);
	else if (keycode == XK_Up)
		move(data, 0.1, 'D');
	else if (keycode == XK_Right)
		move(data, 0.1, 'L');
	else if (keycode == XK_Left)
		move(data, 0.1, 'R');
	else if (keycode == XK_Down)
		move(data, 0.1, 'U');
	else if (keycode == 49)
		data->color = 0x000000;
	else if (keycode == 50)
		generate_color1(data, data->stock);
	else if (keycode == 51)
		generate_color2(data, data->stock);
	else if (keycode == 48)
		get_fractals(data);
	calculate(data);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
	{
		zoom(data, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(data, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(data, (double)x / WIDTH, 'R');
		if (y < 0)
			move(data, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(data, (double)y / HEIGHT, 'D');
	}
	else if (keycode == 5)
		zoom(data, 2);
	else
		return (0);
	calculate(data);
	return (0);
}
