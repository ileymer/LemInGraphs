/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:28:36 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 14:31:28 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			room_index(t_map *m, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (m->rooms[++index] && index < m->q_rooms)
	{
		if (ft_strcmp(m->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}

static void	validate_link(t_map *m, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, m, 1);
	free_array(l, m, 0);
}

void		create_tab(t_map *m)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(m->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		validate_link(m, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(m, l[0], 1)) >= m->q_rooms ||
			(r_2 = room_index(m, l[1], 1)) >= m->q_rooms)
		{
			free_array(l, m, 0);
			free_array(links, m, 1);
		}
		m->tab[r_1][r_2] = 1;
		m->tab[r_2][r_1] = 1;
		free_array(l, m, 0);
	}
	free_array(links, m, 0);
}
