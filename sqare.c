/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqare.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:29:36 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/27 11:29:37 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_sqare(double a, double b, t_fr *f, t_pifag *p)
{
	p->x1 = floor(WIN_WIDTH / 2 + a * cos(b + M_PI / 4));
	p->y1 = floor(WIN_HEIGHT / 2 + a * sin(b + M_PI / 4));
	p->x2 = floor(WIN_WIDTH / 2 + a * cos(b + 3 * M_PI / 4));
	p->y2 = floor(WIN_HEIGHT / 2 + a * sin(b + 3 * M_PI / 4));
	if ((p->x1 > -500 && p->x1 < 1500 && p->y1 > -400 && p->y1 < 1200)
			|| (p->x2 > -500 && p->x2 < 1500 && p->y2 > -400 && p->y2 < 1200))
		brasenham(f, p, 0x1E90FF + f->col_man, -1);
	p->x2 = floor(WIN_WIDTH / 2 + a * cos(b + 7 * M_PI / 4));
	p->y2 = floor(WIN_HEIGHT / 2 + a * sin(b + 7 * M_PI / 4));
	if ((p->x1 > -500 && p->x1 < 1500 && p->y1 > -400 && p->y1 < 1200)
		|| (p->x2 > -500 && p->x2 < 1500 && p->y2 > -400 && p->y2 < 1200))
		brasenham(f, p, 0xFF4500 + f->col_man, -1);
	p->x1 = floor(WIN_WIDTH / 2 + a * cos(b + 5 * M_PI / 4));
	p->y1 = floor(WIN_HEIGHT / 2 + a * sin(b + 5 * M_PI / 4));
	if ((p->x1 > -500 && p->x1 < 1500 && p->y1 > -400 && p->y1 < 1200)
		|| (p->x2 > -500 && p->x2 < 1500 && p->y2 > -400 && p->y2 < 1200))
		brasenham(f, p, 0xD2B48C + f->col_man, -1);
	p->x2 = floor(WIN_WIDTH / 2 + a * cos(b + 3 * M_PI / 4));
	p->y2 = floor(WIN_HEIGHT / 2 + a * sin(b + 3 * M_PI / 4));
	if ((p->x1 > -500 && p->x1 < 1500 && p->y1 > -400 && p->y1 < 1200)
		|| (p->x2 > -500 && p->x2 < 1500 && p->y2 > -400 && p->y2 < 1200))
		brasenham(f, p, 0x7FFF00 + f->col_man, -1);
}

void	sqare(t_fr *f)
{
	double	a;
	double	d;
	double	zoom;
	t_pifag	p;

	f->col_man++;
	f->image = mlx_new_image(f->win, WIN_WIDTH, WIN_HEIGHT);
	f->im = mlx_get_data_addr(f->image, &f->bpp, &f->sl, &f->endian);
	d = M_PI / 20;
	a = 0;
	zoom = f->zoom;
	while (zoom >= 1)
	{
		draw_sqare(zoom, a, f, &p);
		a = a + d;
		zoom = zoom * sin(M_PI / 4) / sin(3 * M_PI / 4 - d);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_destroy_image(f->mlx, f->image);
}
