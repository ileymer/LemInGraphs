/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:02:07 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 13:13:46 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		size_ways(t_map *p)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
			k++;
		i++;
	}
	p->ways = (int **)malloc(sizeof(int *) * k);
	p->w_a = (int **)malloc(sizeof(int *) * k);
	p->k_w = k;
	i = 0;
	while (i < k)
	{
		p->ways[i] = NULL;
		p->w_a[i] = NULL;
		i++;
	}
	return (0);
}

void	sort_ways(int **w_a, int n)
{
	int i;
	int f;
	int k;
	int b;

	f = 1;
	while (f == 1)
	{
		f = 0;
		i = 0;
		while (i < n - 1)
		{
			if (w_a[i][0] > w_a[i + 1][0])
			{
				f = 1;
				b = w_a[i][1];
				k = w_a[i][0];
				w_a[i][0] = w_a[i + 1][0];
				w_a[i][1] = w_a[i + 1][1];
				w_a[i + 1][0] = k;
				w_a[i + 1][1] = b;
			}
			i++;
		}
	}
}

int		count_way(t_map *p, int i)
{
	int j;

	j = 0;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
		{
			p->n++;
			return (count_way(p, j));
		}
		j++;
	}
	return (0);
}
