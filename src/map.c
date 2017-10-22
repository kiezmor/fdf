/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:31:20 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/22 19:13:51 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_char(char c)
{
	if (ft_isdigit(c) && c == ' ' && c == '-')
		;
	else
		errors(4);
}

int		count_col(char **tab, t_info *i)
{
	int	s;
	
	s = 0;
	while(tab[s])
		s++;
	i->ylines = s;
	if(i->bol == 0)
		i->ylines_check = s;
	return (i);
}

int		count_line(char *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY)
	while(get_next_line(fd, &line) > 0)
		i++;
	close(fd);
	return (i);
}

int		*stock_tab(char *str, t_info *i)
{
	int		s;
	char	**tmp;
	int		tab;

	tab = NULL;
	s = 0;
	tmp = ft_strsplit(str, ' ');
	while(tmp[s])
	{
		check_char(*tmp[i]);
		tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if(!(i))
		errors(4);
	return (tab);
}

void	open_map(t_info *i, char *map)
{
	int		fd;
	int		lc;
	char	*line;
	int		c;

	c = 0;
	fd = open(map, O_RDONLY);
	lc = count_line(map);
	i->tab = (int **)malloc(sizeof(int *) * lines);
	ft_memset(i, 0, sizeof(i));
	while((get_next_line(fd, &line)) > 0)
	{
		i->tab[c] = stock_tab(line, lc);
		i->bol = 1;
		if (i->yline != i->ylines_check)
			errors(4);
		c++;
	}
	i->xlines = c;
	if (i->xlines == 0)
		errors(4);
	i->tab[c] = NULL;
	i->map_name = map;
	init_win(i);
}
