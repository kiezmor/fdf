/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:24:26 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/20 03:50:13 by vpluchar         ###   ########.fr       */
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
# define ERROR { exit(EXIT_FAILURE); }

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	void	*mlx_img;
	char	*ptr_img;
	int		**tab;
	int		x;
	int		y;
	int		xlines;
	int		ylines;
	int		ylines_check;
	int		ypos;
	int		xpos;
	float	zoom;
	int		deep;
	float	flat;
	int		mode;
	float	red;
	float	green;
	float	blue;
	int		bol;
	int		bpp;
	int		sl;
	int		ian;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		err2;
	char	*map_name;
}				t_info;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

void	init_win(t_info *i);

#endif
