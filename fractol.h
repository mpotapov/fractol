/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:14:01 by mpotapov          #+#    #+#             */
/*   Updated: 2017/10/13 15:14:04 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libc.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include "libft/libft.h"
# define WIN_WIDTH 1000.0
# define WIN_HEIGHT 800.0
# define MAXX 4
# define ITER 150

typedef	struct		s_pifag
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				deltax;
	int				deltay;
	int				incdeltax;
	int				incdeltay;
	int				h_delta;
	int				err;
	int				delta_err;
	int				incr_x;
	int				incr_y;
}					t_pifag;

typedef struct		s_fr
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*im;
	int				bpp;
	int				sl;
	int				endian;
	int				fractol;
	int				col_man;
	double			zoom;
	double			movex;
	double			movey;
	int				iter;
	double			jul;
	boolean_t		jp;
	pthread_attr_t	attr;
	int				n;
	int				m;
}					t_fr;

typedef struct		s_data
{
	int				xmin;
	int				i;
	int				xmax;
	double			x;
	double			y;
	t_fr			*f;
}					t_data;

int					ft_key(int code, t_fr *f);
void				mandelbrot(t_fr *f, int i);
int					ft_mouse(int code, int x, int y, t_fr *f);
void				put_pxl_to_img(t_fr *f, int x, int y, int col);
int					julia(t_fr *f, int i);
void				choose(t_fr *f);
void				init_fractals(t_fr *f);
int					expose(int x, int y, t_fr *f);
void				menu(t_fr *f);
void				fractals(int i);
int					menu_key(int c, t_fr *f);
int					menu_mouse(int c, int x, int y, t_fr *f);
void				burn_ship(t_fr *fm, int i);
void				brasenham(t_fr *f, t_pifag *p, int col, int k);
void				draw_pif(t_fr *f);
void				put_pxl_to_img_bsh(t_fr *f, int x, int y, int col);
void				sqare(t_fr *f);

#endif
