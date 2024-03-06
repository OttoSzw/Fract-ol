/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:16:37 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:39 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel_color(t_data *data, int x, int y, int color)
{
	data->addr[x * 4 + y * WIDTH * 4] = color;
	data->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	data->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	data->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
	my_mlx_pixel_put(data, x, y, color);
}

int	generate_color(int res)
{
	int	gray_value;

	gray_value = 255 - (res * 255 / 100);
	return ((gray_value << 16) | (gray_value << 8) | gray_value);
}

void	generate_color1(t_data *data, int res)
{
	int	blue;
	int	red;
	int	green;

	red = 100 - (res * 255 / 100);
	green = 100 - (res * 255 / 100);
	blue = 100 - (res * 255 / 100);
	data->color = (red << 16) | (green << 8) | blue;
}

void	generate_color2(t_data *data, int res)
{
	int	red;
	int	green;
	int	blue;

	red = 200 - (res * 255 / 100);
	green = 200 - (res * 255 / 100);
	blue = 200 - (res * 255 / 100);
	data->color = (red << 16) | (green << 8) | blue;
}
