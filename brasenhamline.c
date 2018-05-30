/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenhamline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:56:39 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/24 15:56:41 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_variables(t_pifag *p)
{
	p->deltax = p->x2 - p->x1;
	p->deltay = p->y2 - p->y1;
	p->incr_x = p->deltax > 0 ? 1 : -1;
	p->incr_y = p->deltay > 0 ? 1 : -1;
	p->deltax = abs(p->deltax);
	p->deltay = abs(p->deltay);
	if (p->deltax > p->deltay)
	{
		p->incdeltax = p->incr_x;
		p->incdeltay = 0;
		p->h_delta = p->deltax;
		p->delta_err = p->deltay;
	}
	else
	{
		p->incdeltax = 0;
		p->incdeltay = p->incr_y;
		p->h_delta = p->deltay;
		p->delta_err = p->deltax;
	}
	p->err = p->h_delta / 2;
}

void	brasenham(t_fr *f, t_pifag *p, int col, int k)
{
	double	x;
	double	y;

	make_variables(p);
	x = p->x1;
	y = p->y1;
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
		put_pxl_to_img_bsh(f, x, y, col);
	while (++k < p->h_delta)
	{
		p->err -= p->delta_err;
		if (p->err < 0)
		{
			p->err += p->h_delta;
			x += p->incr_x;
			y += p->incr_y;
		}
		else
		{
			x += p->incdeltax;
			y += p->incdeltay;
		}
		if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
			put_pxl_to_img_bsh(f, x, y, col);
	}
}
