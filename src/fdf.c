/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 00:39:39 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/20 03:51:38 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "libft.h"

static void	ft_errors(int ac,char **av)
{
	int	fd;

	if (ac > 2)
	{
		ft_putendl_fd("Error, too much arguments.", 2);
		// exit(EXIT_FAILURE);
	}
	else if (ac < 2)
	{
		ft_putendl_fd("Error, missing arguments.", 2);
		// exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error, file not found.", 2);
		// exit(EXIT_FAILURE);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_info	*i;
	i = malloc(sizeof(t_info));
	ft_errors(ac, av);
	init_win(i);
	return (0);
}
