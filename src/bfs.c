/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:29:04 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 12:30:57 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		bfs_layer(t_map *p, t_queue *q, int i)
{
	if (p->s[p->pow_room[q->v][i]] == 0)
	{
		if (q->f == 1)
		{
			if (p->tab[q->v][p->pow_room[q->v][i]] == -1)
			{
				p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
				return (1);
			}
		}
		else
		{
			p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
			return (1);
		}
	}
	return (0);
}

void	bfs_queue(int f, int i, t_map *p, t_queue *q)
{
	if (f == 1)
	{
		p->room[p->pow_room[q->v][i]] = q->v;
		if (p->bl_s[p->pow_room[q->v][i]] == 1 && q->f == 0)
			add_element_end_queue(p->pow_room[q->v][i], q, 1);
		else
			add_element_end_queue(p->pow_room[q->v][i], q, 0);
	}
}

int		bfs_check(t_map *p, t_queue *q, int i)
{
	if (p->room[p->pow_room[q->v][i]] == -1 &&
		p->tab[q->v][p->pow_room[q->v][i]] < 1
		&& check_queue(p->pow_room[q->v][i], q) == 1)
		return (1);
	return (0);
}

int		bfs_check_break(t_map *p, t_queue *q, int i)
{
	if ((p->s[p->q_rooms - 1] != 0 &&
		p->s[p->pow_room[q->v][i]] > p->s[p->q_rooms - 1])
		|| p->pow_room[q->v][i] == p->q_rooms - 1)
		return (1);
	return (0);
}

void	bfs(t_map *p)
{
	int		i;
	t_queue	*q;
	int		f;

	q = (t_queue *)malloc(sizeof(t_queue));
	init_bfs(q, p);
	while (q != 0)
	{
		i = 1;
		while (i <= p->pow_room[q->v][0])
		{
			f = 0;
			if (bfs_check(p, q, i))
			{
				f = bfs_layer(p, q, i);
				if (bfs_check_break(p, q, i))
					break ;
				bfs_queue(f, i, p, q);
			}
			i++;
		}
		q = remove_element(q);
	}
}
