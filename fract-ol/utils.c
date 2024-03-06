/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:17:35 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:17:37 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

static void	error_supp(t_data *data)
{
	ft_putendl_fd("Invalid Arguments ;(", 2);
	clean_exit(data);
}

static int	check_point(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_atod2(t_data *data, char *str, int *signe)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*signe *= -1;
		i++;
	}
	j = i;
	while (str[j])
	{
		if (check_point(str, '.') != 1)
			error_supp(data);
		else if (!(str[j] >= '0' && str[j] <= '9') && str[j] != '.')
			error_supp(data);
		j++;
	}
	return (i);
}

double	ft_atod(t_data *data, char *str)
{
	int		i;
	int		signe;
	double	res;
	double	div;

	res = 0;
	div = 0.1;
	signe = 1;
	i = ft_atod2(data, str, &signe);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	return (res * signe);
}
