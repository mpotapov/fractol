/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 14:12:18 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/14 14:12:20 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom_in(t_fr *f, double x1, double y1)
{
	double x2;
	double y2;

	f->zoom *= 1.1;
	if (f->fractol == 1 || f->fractol == 2)
	{
		x2 = 1.5 * (f->n - WIN_WIDTH / 2) / (0.5 * f->zoom * WIN_WIDTH);
		y2 = (f->m - WIN_HEIGHT / 2) / (0.5 * f->zoom * WIN_HEIGHT);
		f->movex -= x2 - x1;
		f->movey -= y2 - y1;
	}
	if (f->fractol == 3)
	{
		x2 = 0.45 + 2 * 1.7 * ((WIN_WIDTH - f->n) / WIN_WIDTH - 0.5) / f->zoom;
		y2 = 0.5 + 2 * 1.7 * ((WIN_HEIGHT - f->m) / WIN_HEIGHT - 0.5) / f->zoom;
		f->movex -= -(x2 - x1);
		f->movey -= -(y2 - y1);
	}
}

void	mouse_zoom_out(t_fr *f, double x1, double y1)
{
	double x2;
	double y2;

	f->zoom /= 1.1;
	if (f->fractol == 1 || f->fractol == 2)
	{
		x2 = 1.5 * (f->n - WIN_WIDTH / 2) / (0.5 * f->zoom * WIN_WIDTH);
		y2 = (f->m - WIN_HEIGHT / 2) / (0.5 * f->zoom * WIN_HEIGHT);
		f->movex -= x2 - x1;
		f->movey -= y2 - y1;
	}
	if (f->fractol == 3)
	{
		x2 = 0.45 + 2 * 1.7 * ((WIN_WIDTH - f->n) / WIN_WIDTH - 0.5) / f->zoom;
		y2 = 0.5 + 2 * 1.7 * ((WIN_HEIGHT - f->m) / WIN_HEIGHT - 0.5) / f->zoom;
		f->movex -= -(x2 - x1);
		f->movey -= -(y2 - y1);
	}
}

int		ft_mouse(int code, int xxx, int yyy, t_fr *f)
{
	double x1;
	double y1;

	f->n = xxx;
	f->m = yyy;
	if (f->fractol == 1 || f->fractol == 2)
	{
		x1 = 1.5 * (xxx - WIN_WIDTH / 2) / (0.5 * f->zoom * WIN_WIDTH);
		y1 = (yyy - WIN_HEIGHT / 2) / (0.5 * f->zoom * WIN_HEIGHT);
	}
	if (f->fractol == 3)
	{
		x1 = 0.45 + 2 * 1.7 * ((WIN_WIDTH - xxx) / WIN_WIDTH - 0.5) / f->zoom;
		y1 = 0.5 + 2 * 1.7 * ((WIN_HEIGHT - yyy) / WIN_HEIGHT - 0.5) / f->zoom;
	}
	if (code == 4)
		mouse_zoom_in(f, x1, y1);
	if (code == 5)
		mouse_zoom_out(f, x1, y1);
	else if (code == 7)
		f->movex += 0.05 / f->zoom;
	else if (code == 6)
		f->movex -= 0.05 / f->zoom;
	choose(f);
	return (0);
}

void	ft_key2(int code, t_fr *f)
{
	if (code == 18)
		f->iter -= 10;
	else if (code == 19)
		f->iter += 10;
	else if (code == 49)
		init_fractals(f);
	else if (code == 1 && f->fractol == 4 && f->m >= 1)
		f->m--;
	else if (code == 0 && f->fractol == 4 && f->n >= 1)
		f->n--;
	else if (code == 13 && f->fractol == 4 && f->m <= 10)
		f->m++;
	else if (code == 12 && f->fractol == 4 && f->n <= 10)
		f->n++;
	else if (code == 35 && f->jp == 0)
		f->jp = 1;
	else if (code == 35 && f->jp == 1)
		f->jp = 0;
}

int		ft_key(int code, t_fr *f)
{
	if (code == 53)
		exit(0);
	else if (code == 6)
		f->col_man -= 1;
	else if (code == 7)
		f->col_man += 1;
	else if (code == 69)
		f->zoom *= 1.1;
	else if (code == 78)
		f->zoom /= 1.1;
	else if (code == 123)
		f->movex -= 0.05 / f->zoom;
	else if (code == 124)
		f->movex += 0.05 / f->zoom;
	else if (code == 126)
		f->movey -= 0.05 / f->zoom;
	else if (code == 125)
		f->movey += 0.05 / f->zoom;
	else
		ft_key2(code, f);
	choose(f);
	return (0);
}
