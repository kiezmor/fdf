/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:38:12 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/27 18:20:51 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	para_change(t_info *i, int key)
{
	i->ypos += (key == 125) ? 10 : 0;
	i->xpos += (key == 124) ? 10 : 0;
	i->ypos -= (key == 126) ? 10 : 0;
	i->xpos -= (key == 123) ? 10 : 0;
	if (i->zoom < 100)
		i->zoom += (key == 69) ? 1 : 0;
	if (i->zoom > 1)
		i->zoom -= (key == 78) ? 1 : 0;
	i->deep += (key == 88) ? 1 : 0;
	if (i->deep > 1)
		i->deep -= (key == 92) ? 1 : 0;
	if (i->flat < 1.7)
		i->flat += (key == 91) ? 0.1 : 0;
	if (i->flat > -1.3)
		i->flat -= (key == 87) ? 0.1 : 0;
	if (key == 83)
	{
		if (i->mode == 0)
			i->mode = 1;
		else
			i->mode = 0;
	}
	if (key == 53)
		exit(0);
}

int		key_print(int key, t_info *i)
{
	para_change(i, key);
	put_img(i);
	return (0);
}

void	r_menu(t_info *s)
{
	mlx_string_put(s->mlx, s->win, 15, 0, 0xFFFFFF, \
	"___________________________");
	mlx_string_put(s->mlx, s->win, 15, 20, 0xFFFFFF, \
	"|           MENU          |");
	mlx_string_put(s->mlx, s->win, 15, 40, 0xFFFFFF, \
	"| MAP:");
	mlx_string_put(s->mlx, s->win, 80, 40, 0xFFFFFF, s->map_name);
	mlx_string_put(s->mlx, s->win, 275, 40, 0xFFFFFF, "|");
	mlx_string_put(s->mlx, s->win, 15, 60, 0xFFFFFF, \
	"| MOVE : Arrows           |");
	mlx_string_put(s->mlx, s->win, 15, 80, 0xFFFFFF, \
	"| ZOOM : + / -            |");
	mlx_string_put(s->mlx, s->win, 15, 100, 0xFFFFFF, \
	"| DEEP : 6 / 9            |");
	mlx_string_put(s->mlx, s->win, 15, 120, 0xFFFFFF, \
	"| CHANGE MODE : 1         |");
	mlx_string_put(s->mlx, s->win, 15, 140, 0xFFFFFF, \
	"| ROTATION : 5 / 8        |");
	mlx_string_put(s->mlx, s->win, 15, 160, 0xFFFFFF, \
	"| EXIT : ESC              |");
	mlx_string_put(s->mlx, s->win, 15, 170, 0xFFFFFF, \
	"___________________________");
}

void	l_menu(t_info *s)
{
	char	*tmp;

	mlx_string_put(s->mlx, s->win, (WDT - 285), 0, 0xFFFFFF, \
	"___________________________");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 20, 0xFFFFFF, \
	"|           PARAMS        |");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 40, 0xFFFFFF, \
	"| MODE :                  |");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 60, 0xFFFFFF, \
	"| DEEP :                  |");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 80, 0xFFFFFF, \
	"| ZOOM :                  |");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 100, 0xFFFFFF,\
	"| FLAT :                  |");
	mlx_string_put(s->mlx, s->win, (WDT - 285), 110, 0xFFFFFF,\
	"___________________________");
	mlx_string_put(s->mlx, s->win, (WDT - 190), 60, 0xFFFFFF, \
		(tmp = ft_itoa(s->deep)));
	free(tmp);
	mlx_string_put(s->mlx, s->win, (WDT - 190), 80, 0xFFFFFF, \
		(tmp = ft_itoa(s->zoom)));
	free(tmp);
	mlx_string_put(s->mlx, s->win, (WDT - 190), 100, 0xFFFFFF, \
		(tmp = ft_itoa(s->flat)));
	free(tmp);
}

void	menu(t_info *i)
{
	r_menu(i);
	l_menu(i);
	mod(i);
}
