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

void	errors(int id)
{
	if (id == 1)
		ft_putendl_fd("Error, too much arguments.", 2);
	if (id == 2)
		ft_putendl_fd("Error, missing arguments.", 2);
	if (id == 3)
		ft_putendl_fd("Error, file not found.", 2);
	if (id == 4)
		ft_putendl_fd("Error, invalid file.", 2);
	ft_putendl("Usage:\t./fdf <map>");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_info	*i;
	int		fd;

	i = malloc(sizeof(t_info));
	if (ac > 2)
		errors(1);
	if (ac < 2)
		errors(2);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		errors(3);
	close(fd);
	open_map(i, av[1]);
}
