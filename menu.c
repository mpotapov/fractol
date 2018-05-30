/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:12:42 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/20 14:12:44 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	info(void)
{
	t_fr f;

	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 600, 300, "INFO");
	mlx_clear_window(f.mlx, f.win);
	mlx_string_put(f.mlx, f.win, 5, 25, 0xFFFFFF, "To zoom "
			"in/out use mouse wheel or '+'/'-'");
	mlx_string_put(f.mlx, f.win, 5, 50, 0xFFFFFF, "To change "
			"color press 'z'/'x'");
	mlx_string_put(f.mlx, f.win, 5, 75, 0xFFFFFF, "To make more iterations "
			"of fractal press '1'/'2'");
	mlx_string_put(f.mlx, f.win, 5, 100, 0xFFFFFF, "Press 'p' to turn the "
			"variable of Julia");
	mlx_string_put(f.mlx, f.win, 5, 125, 0xFFFFFF, "Press 'q'/'w'/'a'/'s' "
			"to change the Pifagor tree");
	mlx_string_put(f.mlx, f.win, 5, 150, 0xFFFFFF, "Press Space to move "
			"fractal to the start position");
	mlx_string_put(f.mlx, f.win, 5, 175, 0xFFFFFF, "Press arrows or mouse "
			"wheel to move fractal");
	mlx_hook(f.win, 2, 3, ft_key, &f);
	mlx_loop(f.mlx);
}

void	menu_mouse2(int c, int x, int y)
{
	if (c == 1 && x > 126 && x < 175 && y > 304 && y < 321)
	{
		fork();
		fractals(5);
	}
	else if (c == 1 && x > 127 && x < 175 && y > 352 && y < 368)
	{
		fork();
		info();
	}
}

int		menu_mouse(int c, int x, int y, t_fr *f)
{
	f = NULL;
	if (c == 1 && x > 100 && x < 205 && y > 106 && y < 120)
	{
		fork();
		fractals(1);
	}
	else if (c == 1 && x > 126 && x < 176 && y > 155 && y < 171)
	{
		fork();
		fractals(2);
	}
	else if (c == 1 && x > 91 && x < 211 && y > 205 && y < 220)
	{
		fork();
		fractals(3);
	}
	else if (c == 1 && x > 113 && x < 190 && y > 255 && y < 275)
	{
		fork();
		fractals(4);
	}
	else
		menu_mouse2(c, x, y);
	return (0);
}

int		menu_key(int c, t_fr *f)
{
	f = NULL;
	if (c == 46)
	{
		fork();
		fractals(1);
	}
	else if (c == 38)
	{
		fork();
		fractals(2);
	}
	else if (c == 11)
	{
		fork();
		fractals(3);
	}
	else if (c == 53)
		exit(0);
	return (0);
}

void	menu(t_fr *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_string_put(f->mlx, f->win, 80, 50, 0xFFFFFF, "Choose Fractal:");
	mlx_string_put(f->mlx, f->win, 100, 100, 0xFF4500, "Mandelbrot");
	mlx_string_put(f->mlx, f->win, 125, 150, 0x00FFFF, "Julia");
	mlx_string_put(f->mlx, f->win, 90, 200, 0xFFD700, "Burning Ship");
	mlx_string_put(f->mlx, f->win, 115, 250, 0xE9967A, "Pifagor");
	mlx_string_put(f->mlx, f->win, 129, 300, 0x7FFF00, "Tube");
	mlx_string_put(f->mlx, f->win, 129, 350, 0xFFFFFF, "INFO");
}
