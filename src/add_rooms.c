/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:21:03 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 14:27:48 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_start_end(t_map *m, char **r, int end)
{
	if (end)
	{
		m->rooms[m->q_rooms - 1] = ft_strdup(r[0]);
		(m->run[1])++;
		return ;
	}
	m->rooms[0] = ft_strdup(r[0]);
	(m->run[0])++;
}

static void	good(t_map *m, char **line, char **r, int end)
{
	if (++(m->run[end]) > 1)
	{
		free_array(r, m, 0);
		free_array(line, m, 1);
	}
}

static void	is_valid(t_map *m, int j, char **r)
{
	int r_index;

	r_index = room_index(m, r[0], 0);
	if (r_index > 0 && j != r_index)
	{
		free_array(r, m, 0);
		exit_func(m, 1, "invalid room\n");
	}
	m->rooms[j] = ft_strdup(r[0]);
}

void		add_rooms(t_map *m)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(m->rooms_list, '\n');
	while (line[++i] && j < m->q_rooms)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			good(m, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			good(m, line, r, 1);
		else if (m->run[0] == 1 && line[i][0] != '#')
			check_start_end(m, r, 0);
		else if (m->run[1] == 1 && line[i][0] != '#')
			check_start_end(m, r, 1);
		else if (line[i][0] != '#')
			is_valid(m, j++, r);
		free_array(r, m, 0);
	}
	free_array(line, m, 0);
}
