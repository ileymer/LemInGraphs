/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:49:50 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 14:49:53 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->q_rooms);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->q_rooms + 1));
	while (++i < m->q_rooms)
	{
		m->rooms[i] = NULL;
		m->tab[i] = (int*)ft_memalloc(sizeof(int) * m->q_rooms);
		j = -1;
		while (m->tab[i][++j])
			m->tab[i][j] = 0;
	}
	m->rooms[i] = NULL;
	return (m);
}

static void		read_map(t_map *m)
{
	char	*line;
	int		clean[3];

	clean[0] = 0;
	clean[1] = 0;
	clean[2] = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
		{
			count_ants(m, line);
			if (clean[0]++ != 0)
				ft_strdel(&line);
		}
		else if (ft_strchr(line, '-') || m->check == 3)
			links(m, line, clean[1]++);
		else if ((m->check == 1 || m->check == 2) && !is_empty(line))
			rooms(m, line, clean[2]++);
		else
			exit_func(m, 1, "invalid map\n");
	}
	ft_strdel(&line);
	if (!m->ants || !m->links[0])
		exit_func(m, 1, "no ants or links\n");
	m = map_init_2(m);
}

static t_map	*map_init(void)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->links = ft_strnew(1);
	m->ants_str = ft_strnew(1);
	m->rooms_list = ft_strnew(1);
	m->q_rooms = 0;
	m->ants = 0;
	m->check = 0;
	m->init_2 = 0;
	m->run[0] = 0;
	m->run[1] = 0;
	m->rooms = NULL;
	m->tab = NULL;
	m->e = 0;
	m->m = 0;
	m->w = 0;
	m->a = 0;
	m->k = 0;
	return (m);
}

int				main(int argc, char **argv)
{
	t_map *m;

	m = map_init();
	if (argc > 1)
		read_flags(argc, argv, m);
	read_map(m);
	add_rooms(m);
	if (!m->run[0] || !m->run[1])
		exit_func(m, 1, "no mandatory comments\n");
	create_tab(m);
	print_map(m);
	if (m->m == 1 || m->a == 1)
		print_matrix(m);
	start_alg(m);
	exit_func(m, 0, "OK\n");
	return (0);
}
