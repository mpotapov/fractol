/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pifagor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:47:08 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/24 15:47:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_on_screen(double *a, t_pifag *p)
{
	if ((a[0] >= 0 && a[0] <= 1000 && a[1] >= 0 && a[1] <= 800) ||
		(p->x2 >= 0 && p->x2 <= 1000 && p->y2 >= 0 && p->y2 <= 800))
		return (1);
	return (0);
}

void	pifagor(double *a, t_fr *f, double b, t_pifag *p)
{
	double x;
	double y;
	double l;

	if (a[2] > 1)
	{
		a[2] *= 0.7;
		p->x1 = a[0];
		p->y1 = a[1];
		p->x2 = (int)(a[0] + a[2] * cos(b));
		p->y2 = (int)(a[1] - a[2] * sin(b));
		if (is_on_screen(a, p) == 1)
			brasenham(f, p, a[3], -1);
		a[0] = a[0] + a[2] * cos(b);
		a[1] = a[1] - a[2] * sin(b);
		a[3] -= 50;
		x = a[0];
		y = a[1];
		l = a[2];
		pifagor(a, f, b + M_PI / f->n, p);
		a[0] = x;
		a[1] = y;
		a[2] = l;
		pifagor(a, f, b - M_PI / f->m, p);
	}
}

void	draw_pif(t_fr *f)
{
	t_pifag *p;
	double	a[4];

	p = (t_pifag *)malloc(sizeof(t_pifag));
	mlx_clear_window(f->mlx, f->win);
	f->image = mlx_new_image(f->win, WIN_WIDTH, WIN_HEIGHT);
	f->im = mlx_get_data_addr(f->image, &f->bpp, &f->sl, &f->endian);
	a[0] = WIN_WIDTH / 2;
	a[1] = WIN_HEIGHT * 2 / 3;
	a[2] = 200;
	a[3] = 0xFFFFFF;
	pifagor(a, f, M_PI / 2, p);
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_destroy_image(f->mlx, f->image);
	free(p);
}
