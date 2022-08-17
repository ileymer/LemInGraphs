/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:39:06 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 18:09:52 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	is_number(char **r, t_map *m, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, m, 1);
		}
	}
	else
		free_array(r, m, 1);
}

static void	validate_room(t_map *m, char *line, int i)
{
	char **r;

	if (!ft_strchr(line, ' '))
		exit_func(m, 1, "invalid map\n");
	r = ft_strsplit(line, ' ');
	if (i != 0)
		ft_strdel(&line);
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, m, 1);
	if (r[1])
		is_number(r, m, r[1]);
	if (r[2])
		is_number(r, m, r[2]);
	free_array(r, m, 0);
}

void		rooms(t_map *m, char *line, int i)
{
	m->check = 2;
	m->rooms_list = join_str(m->rooms_list, line);
	if (line[0] == '#')
	{
		if (i != 0)
			ft_strdel(&line);
		return ;
	}
	validate_room(m, line, i);
	m->q_rooms++;
}

void		links(t_map *m, char *line, int j)
{
	if (m->check == 2)
		m->check = 3;
	if (m->check != 3)
	{
		ft_strdel(&line);
		exit_func(m, 1, "no rooms\n");
	}
	m->links = join_str(m->links, line);
	if (j != 0)
		ft_strdel(&line);
}

void		count_ants(t_map *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	m->check = 1;
	m->ants_str = join_str(m->ants_str, line);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((m->ants = ft_atoi(s)) <= 0)
	{
		ft_strdel(&s);
		exit_func(m, 1, "incorrect number of ants\n");
	}
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
		{
			ft_strdel(&s);
			exit_func(m, 1, "no ants\n");
		}
	}
	ft_strdel(&s);
}
