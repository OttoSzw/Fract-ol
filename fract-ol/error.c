/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:16:50 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:51 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	options2(void)
{
	ft_putendl_fd("+=====COMMANDS=====+\n", 1);
	ft_putendl_fd("~ To zoom in or zoom out, you can scroll with the mouse", 1);
	ft_putendl_fd("~ Or you can press + or - on your keyboard !", 1);
	ft_putendl_fd("~ If you want to move the fractal, press arrows keys\n", 1);
	ft_putendl_fd("~ For Color !", 1);
	ft_putendl_fd("To change color, press 1 ~ Black", 1);
	ft_putendl_fd("To change color, press 2 ~ Grey", 1);
	ft_putendl_fd("To change color, press 3 ~ White", 1);
	ft_putendl_fd("To reset the fractal, press 0", 1);
}

static void	options(void)
{
	ft_putendl_fd("+=====FRACTALS DISPONIBLES=====+\n", 1);
	ft_putendl_fd("~ For Mandelbrot, please enter : ./ fractol mandelbrot", 1);
	ft_putendl_fd("~ For Julia, please enter :      ./ fractol julia", 1);
	ft_putendl_fd("~ For Tricorn, please enter :    ./ fractol tricorn\n", 1);
	ft_putendl_fd("~ For Julia :", 1);
	ft_putendl_fd("You can use two values : ... julia <value> <value>", 1);
	ft_putendl_fd("Examples of values : 0.3 + 0.5", 1);
	ft_putendl_fd("Examples of values : 0.285 + 0.01", 1);
	ft_putendl_fd("Examples of values : -0.8 + 0.156\n", 1);
}

void	msg_error(t_data *data)
{
	ft_putendl_fd("\n+=========+", 1);
	ft_putendl_fd("|  (⌐■_■) |", 1);
	ft_putendl_fd("+=========+\n", 1);
	options();
	options2();
	clean_exit(data);
}
