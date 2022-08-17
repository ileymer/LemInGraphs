/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:47:31 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 14:07:02 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_result(t_map *p, int vl[5])
{
	while (vl[3] > 1)
	{
		if (p->s[p->ways[p->w_a[vl[1]][1]][vl[3] - 1]] != 0)
		{
			ft_printf("L%d-%s ", p->s[p->ways[p->w_a[vl[1]][1]][vl[3] - 1]],
			p->rooms[p->ways[p->w_a[vl[1]][1]][vl[3]]]);
			p->s[p->ways[p->w_a[vl[1]][1]][vl[3]]] =
			p->s[p->ways[p->w_a[vl[1]][1]][vl[3] - 1]];
			p->s[p->ways[p->w_a[vl[1]][1]][vl[3] - 1]] = 0;
			if (p->ways[p->w_a[vl[1]][1]][vl[3]] == p->q_rooms - 1)
				vl[2]++;
		}
		vl[3]--;
	}
}

void	print_result_start(t_map *p, int vl[5])
{
	if (vl[3] == 1 && p->w_a[vl[1]][2] > 0)
	{
		ft_printf("L%d-%s ", vl[0],
		p->rooms[p->ways[p->w_a[vl[1]][1]][vl[3]]]);
		p->s[p->ways[p->w_a[vl[1]][1]][vl[3]]] = vl[0]++;
		p->w_a[vl[1]][2]--;
	}
}

void	result_show(t_map *p)
{
	int vl[5];

	vl[0] = 1;
	vl[1] = 0;
	vl[2] = 0;
	vl[4] = 0;
	nool_arr(p->s, p->q_rooms);
	while (vl[2] != p->ants)
	{
		vl[1] = 0;
		while (vl[1] < p->k_w)
		{
			vl[3] = p->w_a[vl[1]][0] - 1;
			print_result(p, vl);
			print_result_start(p, vl);
			vl[1]++;
		}
		ft_printf("\n");
		vl[4]++;
	}
	if (p->k == 1 || p->a == 1)
		ft_printf("Number of output lines - %d\n", vl[4]);
}

int		vivod(int i, t_map *p)
{
	int j;

	j = 0;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
		{
			ft_printf("%s--->", p->rooms[i]);
			vivod(j, p);
			return (1);
		}
		j++;
	}
	return (1);
}

void	vivi(t_map *p)
{
	int i;

	i = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
		{
			ft_printf("%s--->", p->rooms[0]);
			vivod(i, p);
			ft_printf("%s\n\n", p->rooms[p->q_rooms - 1]);
		}
		i++;
	}
}
