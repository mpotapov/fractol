/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:14:24 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/28 15:12:35 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int		main(int ac, char **av)
{
	t_fr	f;

	pthread_attr_init(&f.attr);
	usage(ac, av[1], &f);
	f.iter = ITER;
	if (f.fractol == 0)
	{
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, 300, 400, "Menu");
		menu(&f);
		mlx_hook(f.win, 2, 3, menu_key, &f);
		mlx_mouse_hook(f.win, menu_mouse, &f);
		mlx_loop(f.mlx);
	}
	else
		fractals(f.fractol);
	return (0);
}
