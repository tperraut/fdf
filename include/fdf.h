/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2016/10/02 16:13:03 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define W_MAX 800
# define H_MAX 600
# define DX 1.
# define DY 1.
# define CST 1.
# define W_IMG W_MAX
# define H_IMG H_MAX
# define WHITE 0xFFFFFF
# define CROSS_MASK (1L<<17)
# define CROSS_V 17
# define ENDIAN 0
# define S_PIXEL 3

typedef struct	s_pt
{
	int	x;
	int	y;
	int	z;
}				t_pt;

typedef struct	s_img
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct	s_map
{
	int	**tab;
	int	li;
	int	co;
	int	bw;
	int	cz;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	t_img	*img_data;
	t_map	*map;
	int		op;
}				t_env;

/*
** POINT
*/

void			pt_new(t_pt *p, int x, int y, int z);
void			pt_inv(t_pt *p);
void			pt_iso(t_pt *p, int bw, int cz);

/*
** PARSE
*/

t_map			*parser(int fd);
t_img			*new_img_data(void *img);
void			init_map(t_map **map, int co);
void			free_map(t_map **map);

/*
** CHECK
*/

void			error(const char *s);
# define IF_ERROR(err, msg) if (err) error(msg)

/*
** DEBUG
*/

void			print_map(t_map m);

/*
** DRAW
*/

void			ft_expose(t_env *env);
void			fill_line(t_pt p1, t_pt p2, t_img *img);
int				draw(void *param);

/*
** EVENT
*/

int				manage_key(int keycode, void *param);
int				manage_mouse(int button, int x, int y, void *param);
int				finish(void *param);

#endif
