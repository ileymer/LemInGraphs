/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:56:58 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 12:17:36 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dfs(t_map *p)
{
	int i;

	i = 0;
	while (i < p->q_rooms)
		p->bl[i++] = 0;
	i = 0;
	while (i <= p->pow_room[p->q_rooms - 1][0])
	{
		dfs_one(p->q_rooms - 1, p);
		i++;
	}
	return (0);
}

void	dfs_completion(t_map *p, int i, int e)
{
	p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] - 1;
	p->tab[p->pow_room[e][i]][e] = p->tab[p->pow_room[e][i]][e] + 1;
	p->bl_s[p->pow_room[e][i]] = 1;
	if (p->pow_room[e][i] != 0)
		p->bl[p->pow_room[e][i]] = 1;
}

void	dfs_recoil(t_map *p, int i, int e)
{
	p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] + 1;
	p->tab[p->pow_room[e][i]][e] = p->tab[p->pow_room[e][i]][e] - 1;
	p->bl[p->pow_room[e][i]] = 0;
	p->bl_s[p->pow_room[e][i]] = 0;
}

int		dfs_one(int e, t_map *p)
{
	int i;

	i = 1;
	while (i <= p->pow_room[e][0])
	{
		if (p->bl[p->pow_room[e][i]] == 0 &&
			p->s[e] - 1 == p->s[p->pow_room[e][i]]
			&& ((p->tab[e][p->pow_room[e][i]] >= 0 && e != p->q_rooms - 1)
				|| (p->tab[e][p->pow_room[e][i]] == 0 && e == p->q_rooms - 1)))
		{
			if (!(p->pow_room[e][i] == 0 && p->tab[e][p->pow_room[e][i]] != 0))
				dfs_completion(p, i, e);
			if (p->pow_room[e][i] == 0)
				return (1);
			if (dfs_one(p->pow_room[e][i], p) == 0)
				dfs_recoil(p, i, e);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
