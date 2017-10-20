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

# define NAME "FdF"
# define HGT 720
# define WDT 1080

typedef struct	s_info
{
	void	*mlx;
	void	*win;
}				t_info;

void	init_win(t_info *i);

#endif
