/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:01:53 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/15 15:16:50 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

void	f1(char a[100])
{
	int		i;

	i = 0;
	while (i < 100)
		a[i++] = '.';
}

void	print_f1(char a[100], int m[13])
{
	int		i;

	i = 0;
	writeln(1, '.', m);
	m[11]++;
	while (i < 100)
	{
		if (('0' <= a[i]) && (a[i] <= '9'))
		{
			write(1, &a[i], 1);
			m[11]++;
		}
		i++;
	}
}

int		distrib_lf(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'f')
		return (type_lf(vl, m));
	return (0);
}

size_t	ft_strlens(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_bon1(char a[50], int m[13])
{
	int i;

	i = 49;
	while (i >= 0)
	{
		if (a[i] != '.' && m[10] != 1)
		{
			write(1, &a[i], 1);
			m[11]++;
		}
		i--;
	}
}
