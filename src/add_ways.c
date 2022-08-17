/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:13:32 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 13:18:00 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_way(t_map *p, int i, int l, int j)
{
	int q;

	q = 0;
	while (q < p->q_rooms)
	{
		if (p->tab[i][q] == 1)
		{
			p->ways[l][j] = i;
			add_way(p, q, l, ++j);
			return (0);
		}
		q++;
	}
	return (0);
}

void	add_ways(t_map *p)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < p->q_rooms)
	{
		p->n = 1;
		if (p->tab[0][i] == 1)
		{
			count_way(p, i);
			p->ways[j] = (int *)malloc(sizeof(int) * (p->n + 1));
			p->w_a[j] = (int *)malloc(sizeof(int) * (3));
			p->w_a[j][1] = j;
			p->w_a[j++][0] = p->n + 1;
		}
		i++;
	}
	way_plus(p);
}

void	way_plus(t_map *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
		{
			p->ways[j][0] = 0;
			add_way(p, i, j, 1);
			p->ways[j][p->w_a[j][0] - 1] = p->q_rooms - 1;
			j++;
		}
		i++;
	}
}
