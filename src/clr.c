/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:33:46 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/22 19:33:46 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_color(t_info *i, int z)
{
	if (z >= -100 && z <= 2)
	{
		i->blue = 51;
		i->green = 153;
		i->red = 255;
	}
	if (z >= 3 && z <= 15)
	{
		i->blue = 255;
		i->green = 204;
		i->red = 0;
	}
	init_color_two(i, z);
}

void	init_color_two(t_info *i, int z)
{
	if (z >= 16 && z <= 50)
	{
		i->blue = 51;
		i->green = 255;
		i->red = 51;
	}
	if (z >= 51 && z <= 75)
	{
		i->blue = 153;
		i->green = 102;
		i->red = 0;
	}
	if (z >= 76 && z <= 150)
	{
		i->blue = 255;
		i->green = 255;
		i->red = 255;
	}
}
