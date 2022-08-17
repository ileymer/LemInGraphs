/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:31:26 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 14:40:35 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_end(t_map *p)
{
	int a;

	a = 1;
	while (a <= p->ants)
	{
		ft_printf("L%d-%s ", a, p->rooms[p->q_rooms - 1]);
		a++;
	}
	ft_printf("\n");
}

int		check_start(t_map *p)
{
	int i;

	i = 1;
	while (i <= p->pow_room[0][0])
	{
		if (p->pow_room[0][i] == p->q_rooms - 1)
			return (1);
		i++;
	}
	return (0);
}

void	way(t_map *p)
{
	size_ways(p);
	add_ways(p);
	nool_w_a(p->w_a, p->k_w);
	sort_ways(p->w_a, p->k_w);
	if (p->k_w > 1)
		distrib_ants(p);
	else
		p->w_a[0][2] = p->ants;
}

void	alg(t_map *p)
{
	int r;
	int m;
	int f;

	f = 0;
	m = 2000000000;
	while (p->s[p->q_rooms - 1] != 0 || f == 0)
	{
		bfs(p);
		if (p->s[p->q_rooms - 1] == 0 && f == 0)
			exit(0);
		if (p->s[p->q_rooms - 1] == 0)
			break ;
		dfs(p);
		way(p);
		f = 1;
		r = mins(p->w_a, p->k_w);
		dissolve_ways(p);
		if (r < m)
		{
			m = r;
			tabtotab(p->tab, p->tab_final, p->q_rooms);
		}
	}
}

int		start_alg(t_map *p)
{
	init_alg(p);
	init_pow_rooms(p);
	nool_tab(p->tab, p->q_rooms);
	if (check_start(p) == 1)
	{
		start_end(p);
		dissolve(p);
		return (1);
	}
	alg(p);
	tabtotab(p->tab_final, p->tab, p->q_rooms);
	way(p);
	if (p->w == 1 || p->a == 1)
		vivi(p);
	result_show(p);
	dissolve(p);
	dissolve_ways(p);
	return (0);
}
