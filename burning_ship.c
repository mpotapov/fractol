/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:01:42 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/28 15:11:19 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"

void	put_pxl_to_img_bsh(t_fr *f, int x, int y, int col)
{
	f->im[y * f->sl + x * f->bpp / 8] = col;
	f->im[y * f->sl + x * f->bpp / 8 + 1] = col >> 8;
	f->im[y * f->sl + x * f->bpp / 8 + 2] = col >> 16;
}

void	put_pxl_to_img_bsh1(t_fr *f, int x, int y, int col)
{
	f->im[y * f->sl + x * f->bpp / 8] = (char)col;
	f->im[y * f->sl + x * f->bpp / 8 + 1] = (char)col >> 8;
	f->im[y * f->sl + x * f->bpp / 8 + 2] = (char)col >> 16;
}

void	bb_sh(t_data *d, double a, int i, double x)
{
	double ix;
	double iy;
	double cx;
	double cy;

	ix = 0;
	iy = 0;
	cx = 0.45 + 2 * 1.7 * (x / WIN_WIDTH - 0.5) / d->f->zoom - d->f->movex;
	cy = 0.5 + 2 * 1.7 * (d->y / WIN_HEIGHT - 0.5) / d->f->zoom - d->f->movey;
	while (i < d->f->iter)
	{
		a = ix * ix - iy * iy - cx;
		iy = 2 * fabs(ix * iy) - cy;
		ix = a;
		if (ix * ix + iy * iy > 4)
			break ;
		i++;
	}
	if (i != d->f->iter)
		put_pxl_to_img_bsh1(d->f, WIN_WIDTH - x - 1, WIN_HEIGHT - d->y - 1,
							0xFFA07A + i * 0.5 * d->f->col_man);
}

void	*burn_ship_th(void *fr)
{
	t_data *d;
	double x;
	double y;

	d = (t_data *)fr;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = d->xmin;
		while (x < d->xmax + 1)
		{
			d->y = y;
			bb_sh(d, 0, 0, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	burn_ship(t_fr *f, int i)
{
	pthread_t	*tid;
	t_data		*data;

	f->image = mlx_new_image(f->win, WIN_WIDTH, WIN_HEIGHT);
	f->im = mlx_get_data_addr(f->image, &f->bpp, &f->sl, &f->endian);
	tid = (pthread_t *)malloc(3 * sizeof(pthread_t));
	data = (t_data *)malloc(4 * sizeof(t_data));
	while (++i < 4)
	{
		data[i].xmin = 0 + WIN_WIDTH / 4 * i;
		data[i].xmax = WIN_WIDTH / 4 * (i + 1) - 1;
		data[i].f = f;
		data[i].i = i;
		if (i != 3)
			pthread_create(&(tid[i]), NULL, burn_ship_th, &data[i]);
	}
	burn_ship_th(&data[3]);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	free(tid);
	free(data);
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_destroy_image(f->mlx, f->image);
}
