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

void	usage(int ac, char *s, t_fr *f)
{
	f->fractol = 0;
	if (ac == 2)
	{
		!ft_strcmp(s, "mandelbrot") ? f->fractol = 1 : 0;
		!ft_strcmp(s, "julia") ? f->fractol = 2 : 0;
		!ft_strcmp(s, "ship") ? f->fractol = 3 : 0;
		!ft_strcmp(s, "pifagor") ? f->fractol = 4 : 0;
		!ft_strcmp(s, "tube") ? f->fractol = 5 : 0;
		if (f->fractol != 0)
			return ;
	}
	if (ac == 1)
		return ;
	ft_putstr("Usage : \"./fractol (julia | mandelbrot | ship | "
				"pifagor | tube)\" or ./fractol\n");
	exit(1);
}

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
