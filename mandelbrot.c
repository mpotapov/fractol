/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:23:50 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/28 15:06:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pxl_to_img(t_fr *f, int x, int y, int col)
{
	f->im[y * f->sl + x * 4] = (char)col >> 16;
	f->im[y * f->sl + x * 4 + 1] = (char)col >> 8;
	f->im[y * f->sl + x * 4 + 2] = (char)col;
}

void	mm(t_data *d, double a, double n, int i)
{
	double ix;
	double iy;
	double cx;
	double cy;

	i = 0;
	cx = 1.5 * (d->x - WIN_WIDTH / 2) /
		(0.5 * d->f->zoom * WIN_WIDTH) + d->f->movex;
	cy = (d->y - WIN_HEIGHT / 2) /
		(0.5 * d->f->zoom * WIN_HEIGHT) + d->f->movey;
	ix = 0;
	iy = 0;
	n = ix * ix + iy * iy;
	while ((n < MAXX) && (i < d->f->iter))
	{
		a = ix * ix - iy * iy + cx;
		iy = 2 * ix * iy + cy;
		ix = a;
		n = ix * ix + iy * iy;
		i++;
	}
	if (n > 4)
		put_pxl_to_img(d->f, d->x, d->y, 0x00FFFF - i * d->f->col_man);
}

void	*mandpth(void *fr)
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
			d->x = x;
			d->y = y;
			mm(d, 0, 0, 0);
			x++;
		}
		y++;
	}
	return (0);
}

void	mandelbrot(t_fr *f, int i)
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
			pthread_create(&(tid[i]), NULL, mandpth, &data[i]);
	}
	mandpth(&data[3]);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	free(tid);
	free(data);
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_destroy_image(f->mlx, f->image);
}
