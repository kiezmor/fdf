/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:24:26 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/27 18:21:20 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define NAME "FdF"
# define HGT 720
# define WDT 1080

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	void		*mlx_img;
	char		*ptr_img;
	int			**tab;
	int			x;
	int			y;
	int			xlines;
	int			ylines;
	int			ylines_check;
	int			ypos;
	int			xpos;
	float		zoom;
	int			deep;
	float		flat;
	int			mode;
	float		red;
	float		green;
	float		blue;
	int			bol;
	int			bpp;
	int			sl;
	int			ian;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			err2;
	char		*map_name;
}				t_info;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

void			init_win(t_info *i);
void			errors(int id);
int				main(int ac, char **av);
void			check_char(char c);
int				count_col(char **tab, t_info *i);
int				count_line(char *map);
int				*stock_tab(char *str, t_info *i);
void			open_map(t_info *i, char *map);
void			init_co(t_info *i);
void			put_img(t_info *i);
void			init_par(t_info *i);
void			init_win(t_info *i);
void			para_change(t_info *i, int key);
int				key_print(int key, t_info *i);
void			r_menu(t_info *s);
void			l_menu(t_info *s);
void			menu(t_info *i);
void			pixel_to_image(int x, int y, t_info *i);
t_point			calcul(int x, int y, int z, t_info *i);
void			print_trace(t_point p1, t_point p2, t_info *i);
void			printf_map(t_info *i);
void			init_color(t_info *i, int z);
void			init_color_two(t_info *i, int z);
void			mod(t_info *s);

#endif
