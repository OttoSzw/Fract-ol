/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:17:29 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:17:31 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data)
{
	int		max;
	double	n;
	double	temp;

	max = 100;
	data->z_r = 0;
	data->z_i = 0;
	n = 0;
	while (n < max && data->z_r * data->z_r + data->z_i * data->z_i < 4.0)
	{
		temp = 2 * (data->z_r * data->z_i) + data->c_i;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = temp;
		n++;
	}
	return (n);
}
