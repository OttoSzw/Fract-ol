/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:50 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/10 15:34:52 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->tab = NULL;
	data->set = -1;
	data->min_i = 0;
	data->max_i = 0;
	data->minreal = 0;
	data->maxreal = 0;
	data->c_i = 0;
	data->c_r = 0;
	data->z_i = 0;
	data->z_r = 0;
}

static void	args_check(t_data *data, int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 20) == 0 && ac == 2)
		data->set = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", 10) == 0 && ac == 2)
	{
		data->set = JULIA;
		data->j_r = 0.3;
		data->j_i = 0.5;
	}
	else if (ft_strncmp(av[1], "julia", 10) == 0 && ac == 4)
	{
		data->set = JULIA;
		data->j_r = ft_atod(data, av[2]);
		data->j_i = ft_atod(data, av[3]);
	}
	else if (ft_strncmp(av[1], "tricorn", 20) == 0 && ac == 2)
		data->set = TRICORN;
	else
		msg_error(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		msg_error(&data);
	clean_init(&data);
	args_check(&data, ac, av);
	init(&data);
	calculate(&data);
	mlx_hook(data.win, 17, 0, handle_window_close, &data);
	mlx_key_hook(data.win, key_event, &data);
	mlx_mouse_hook(data.win, mouse_event, &data);
	mlx_loop(data.mlx);
	clean_exit(&data);
}
