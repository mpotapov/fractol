/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:08:17 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/20 15:08:18 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose(int x, int y, t_fr *f)
{
	if (x >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT && y >= 0 && f->jp == 1)
		f->jul = 0.084150 + x * 0.000331;
	choose(f);
	return (0);
}

void	init_fractals(t_fr *f)
{
	f->iter = ITER;
	f->zoom = 1;
	f->col_man = 0;
	f->movex = 0;
	f->movey = 0;
	if (f->fractol == 1)
	{
		f->movex = -1;
		f->movey = 0;
	}
	else if (f->fractol == 2)
	{
		f->jp = 0;
		f->jul = 0.27015;
	}
	else if (f->fractol == 3)
		f->col_man = -31;
	else if (f->fractol == 4)
	{
		f->n = 3;
		f->m = 3;
	}
	else if (f->fractol == 5)
		f->zoom = 450;
}

void	choose(t_fr *f)
{
	if (f->fractol == 1)
		mandelbrot(f, -1);
	else if (f->fractol == 2)
		julia(f, -1);
	else if (f->fractol == 3)
		burn_ship(f, -1);
	else if (f->fractol == 4)
		draw_pif(f);
	else if (f->fractol == 5)
		sqare(f);
}

void	fractals(int i)
{
	t_fr	f;

	f.fractol = i;
	init_fractals(&f);
	pthread_attr_init(&f.attr);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	f.image = mlx_new_image(f.win, WIN_WIDTH, WIN_HEIGHT);
	f.im = mlx_get_data_addr(f.image, &f.bpp, &f.sl, &f.endian);
	mlx_put_image_to_window(f.mlx, f.win, f.image, 0, 0);
	mlx_destroy_image(f.mlx, f.image);
	if (f.fractol == 2)
		mlx_hook(f.win, 6, 64, expose, &f);
	mlx_mouse_hook(f.win, ft_mouse, &f);
	mlx_hook(f.win, 2, 3, ft_key, &f);
	choose(&f);
	mlx_loop(f.mlx);
}
