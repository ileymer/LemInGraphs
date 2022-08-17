/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:32:29 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 14:35:02 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clear(t_map *m)
{
	int i;
	int j;

	free(m->links);
	free(m->ants_str);
	free(m->rooms_list);
	if (m->init_2)
	{
		j = (!m->run[0]) ? 1 : 0;
		while (m->rooms[j])
		{
			(m->rooms[j]) ? free(m->rooms[j]) : 0;
			j++;
		}
		free(m->rooms);
		i = -1;
		while (++i < m->q_rooms)
			free(m->tab[i]);
		free(m->tab);
	}
	free(m);
}

void		exit_func(t_map *m, int error, char *message)
{
	int e;
	int a;

	e = m->e;
	a = m->a;
	clear(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		if (message && (e == 1 || a == 1))
			ft_putstr_fd(message, 2);
		exit(1);
	}
	exit(0);
}
