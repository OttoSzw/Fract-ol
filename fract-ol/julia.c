/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:17:18 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:17:19 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *data)
{
	int		max;
	double	n;
	double	temp;

	max = 100;
	n = 0;
	while (n < max && data->c_r * data->c_r + data->c_i * data->c_i < 4.0)
	{
		temp = 2 * (data->c_r * data->c_i) + data->j_i;
		data->c_r = data->c_r * data->c_r - data->c_i * data->c_i + data->j_r;
		data->c_i = temp;
		n++;
	}
	return (n);
}
