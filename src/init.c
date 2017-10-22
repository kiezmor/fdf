/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:25:45 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/22 19:13:45 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_co(t_info *i)
{
	i->x = 0;
	i->y = 0;
}

void	put_img(t_info *i)
{
	i->mlx_img = mlx_new_image(i->mlx, WDT, HGT);
	i->ptr_img = mlx_get_data_addr(i->mlx_img, &(i->bpp), &(i->sl), &(i->ian));
	init_co(i);
	printf_map(i);
	mlx_put_image_to_window(i->mlx, i->win, i->mlx_img, 0, 0);
	menu(i);
	mlx_destroy_image(i->mlx, i->ptr_img);
}

void	init_par(t_info *i)
{
	i->deep = 10;
	i->ypos = HGT / 4;
	i->xpos = WDT / 2;
	i->zoom = 10.0;
	i->mode = 0;
	i->flat = 0.80;
}

void	init_win(t_info *i)
{
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, WDT, HGT, NAME);
	init_par(i);
	put_img(i);
	mlx_hook(i->win, 2, 3, key_print, i);
	mlx_loop(i->mlx);
}