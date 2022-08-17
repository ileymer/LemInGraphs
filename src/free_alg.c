/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:52:49 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 12:54:53 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dissolve(t_map *p)
{
	int i;

	i = 0;
	while (i < p->q_rooms)
	{
		if (p->pow_room[i])
			free(p->pow_room[i]);
		free(p->tab_final[i]);
		i++;
	}
	free(p->room);
	free(p->s);
	free(p->bl);
	free(p->bl_s);
	free(p->tab_final);
	free(p->pow_room);
}

void	dissolve_ways(t_map *p)
{
	int i;

	i = 0;
	while (i < p->k_w)
	{
		if (p->w_a[i])
			free(p->w_a[i]);
		if (p->ways[i])
			free(p->ways[i]);
		i++;
	}
	free(p->ways);
	free(p->w_a);
}
