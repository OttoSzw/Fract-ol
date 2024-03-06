/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:17:12 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:17:14 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_fractals(t_data *data)
{
	data->minreal = -2.0;
	data->maxreal = 2.0;
	data->min_i = -2.0;
	data->max_i = data->min_i + (data->maxreal - data->minreal) * HEIGHT
		/ WIDTH;
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "MY Fractol");
	if (data->win == NULL)
	{
		free(data->mlx);
		return ;
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->color = 0x000000;
	get_fractals(data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
