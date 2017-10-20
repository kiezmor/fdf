/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 23:07:16 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/19 23:11:42 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int	key(int key, void *par)
{
	par = 0;
	printf("key: [%d]\n", key);
	if (key == 53)
		exit(1);
	return(0);
}

int	main()
{
	void *mlx_ptr;
	void *win_ptr;
	int	x;
	int	y;

	mlx_ptr = mlx_init();
	if (!(win_ptr = mlx_new_window(mlx_ptr, 420, 420, "42")))
		return (1);
	mlx_string_put(mlx_ptr, win_ptr, 20, 20, 0xFFFFFF, "IL EST BO LE CARRER");
	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_key_hook(win_ptr, key, 0);
	mlx_loop(mlx_ptr);
	return(0);
}
