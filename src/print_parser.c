/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:50:00 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 14:50:02 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_map(t_map *m)
{
	int i;

	i = -1;
	ft_putendl(m->ants_str);
	ft_putendl(m->rooms_list);
	ft_putendl(m->links);
	ft_putchar('\n');
}

static void	header(t_map *m)
{
	int i;

	i = -1;
	ft_putstr("   ");
	while (++i < m->q_rooms)
	{
		ft_putchar(' ');
		ft_putnbr((i > 9) ? (i % 10) : i);
	}
	ft_putstr("\n\n");
}

void		print_matrix(t_map *m)
{
	int i;
	int j;

	header(m);
	i = -1;
	while (++i < m->q_rooms)
	{
		ft_putnbr((i > 9) ? (i % 10) : i);
		ft_putstr("   ");
		j = -1;
		while (++j < m->q_rooms)
		{
			ft_putnbr(m->tab[i][j]);
			ft_putchar(' ');
		}
		ft_putstr("\t");
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] - ");
		ft_putendl(m->rooms[i]);
	}
	ft_putstr("\n");
}
