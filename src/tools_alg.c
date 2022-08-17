/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:08:20 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 14:09:55 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	nool_w_a(int **w_a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		w_a[i++][2] = 0;
	}
}

void	tabtotab(int **t, int **t2, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			t2[i][j] = t[i][j];
			j++;
		}
		i++;
	}
}

void	nool_arr(int *m, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		m[i++] = 0;
	}
}

void	nool_tab(int **tab, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			tab[i][j++] = 0;
		}
		i++;
	}
}
