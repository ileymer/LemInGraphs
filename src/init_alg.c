/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:33:29 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 17:03:04 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_alg(t_map *p)
{
	int i;

	i = 0;
	p->room = (int *)malloc(sizeof(int) * p->q_rooms);
	p->s = (int *)malloc(sizeof(int) * p->q_rooms);
	p->bl = (int *)malloc(sizeof(int) * p->q_rooms);
	p->bl_s = (int *)malloc(sizeof(int) * p->q_rooms);
	p->pow_room = (int **)malloc(sizeof(int *) * p->q_rooms);
	p->tab_final = (int **)malloc(sizeof(int *) * p->q_rooms);
	while (i < p->q_rooms)
	{
		p->bl[i] = 0;
		p->tab_final[i] = (int *)malloc(sizeof(int) * p->q_rooms);
		p->pow_room[i] = NULL;
		p->bl_s[i] = 0;
		p->s[i] = 0;
		p->room[i++] = 0;
	}
}

void	add_pow(int i, t_map *p)
{
	int j;
	int q;

	j = 0;
	q = 1;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
			p->pow_room[i][q++] = j;
		j++;
	}
}

void	init_pow_rooms(t_map *p)
{
	int i;
	int k;
	int j;

	i = 0;
	while (i < p->q_rooms)
	{
		j = 0;
		k = 0;
		while (j < p->q_rooms)
			if (p->tab[i][j++] == 1)
				k++;
		if (k != 0)
		{
			p->pow_room[i] = (int *)malloc(sizeof(int) * (k + 1));
			j = 0;
			p->pow_room[i][0] = k;
			add_pow(i, p);
		}
		i++;
	}
}

void	init_bfs(t_queue *q, t_map *p)
{
	int		i;

	i = 0;
	q->v = 0;
	q->f = 0;
	q->next = NULL;
	while (i < p->q_rooms)
	{
		p->s[i] = 0;
		p->room[i] = -1;
		i++;
	}
	p->room[0] = 0;
}
