/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:25:24 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/22 19:25:24 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_to_image(int x, int y, t_info *i)
{
	if (x < WDT && y < HGT && x > 0 && y > 0)
	{
		i->ptr_img[(i->sl * y) + (4 * x) + 2] = i->blue;
		i->ptr_img[(i->sl * y) + (4 * x) + 1] = i->green;
		i->ptr_img[(i->sl * y) + (4 * x)] = i->red;
	}
}

t_point		calcul(int x, int y, int z, t_info *i)
{
	t_point point;

	if (i->mode == 0)
	{
		point.x = i->xpos + ((sqrt(2.0) / 2.0) * ((x * i->zoom) -\
		(y * i->zoom)));
		point.y = i->ypos - ((sqrt(2.0 / 2.0) * (z * i->zoom / i->deep)) -
		((i->flat / sqrt(9.0)) * (i->zoom * (x + y))));
		return (point);
	}
	else
	{
		point.x = i->xpos + ((x * i->zoom) + i->flat * (y * i->zoom));
		point.y = i->ypos -\
			((z * i->zoom / i->deep) - i->flat * (y * i->zoom));
		return (point);
	}
}

void		print_trace(t_point p1, t_point p2, t_info *i)
{
	i->dx = abs((p2.x - p1.x));
	i->sx = p1.x < p2.x ? 1 : -1;
	i->dy = abs((p2.y - p1.y));
	i->sy = p1.y < p2.y ? 1 : -1;
	i->err = (i->dx > i->dy ? i->dx : -i->dy) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		pixel_to_image(p1.x, p1.y, i);
		i->err2 = i->err;
		if (i->err2 > -i->dx)
		{
			i->err -= i->dy;
			p1.x += i->sx;
		}
		if (i->err2 < i->dy)
		{
			i->err += i->dx;
			p1.y += i->sy;
		}
	}
}

void		printf_map(t_info *i)
{
	t_point p1;
	t_point p2;

	while (i->y < i->xlines)
	{
		while (i->x < i->ylines)
		{
			p1 = calcul(i->x, i->y, i->tab[i->y][i->x], i);
			i->x++;
			init_color(i, i->tab[i->y][i->x]);
			if (i->x < i->ylines)
			{
				p2 = calcul(i->x, i->y, i->tab[i->y][i->x], i);
				print_trace(p1, p2, i);
			}
			if (i->y < i->xlines - 1)
			{
				p2 = calcul(i->x - 1, i->y + 1, i->tab[i->y + 1][i->x - 1], i);
				print_trace(p1, p2, i);
			}
		}
		i->x = 0;
		i->y++;
	}
}
