/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:55:54 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/15 15:23:20 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

void	nulls(int m[13])
{
	write(1, "(null)", m[6]);
	m[11] = m[11] + m[6];
}

void	writes(char *s, int m[13])
{
	int		i;

	i = 0;
	while (s[i] != '\0' && i < m[6])
	{
		write(1, &s[i], 1);
		m[11]++;
		i++;
	}
}

void	print_s(int m[8], char *n)
{
	int		k;
	int		f;

	f = 0;
	if (n == NULL)
	{
		f = 1;
		if (m[7] != 1)
			m[6] = 6;
		else if (m[6] > 6)
			m[6] = 6;
	}
	else
	{
		k = ft_strlens(n);
		if (m[7] == 0)
			m[6] = k;
		else
		{
			if (k < m[6])
				m[6] = k;
		}
	}
	print_s1(m, n, f);
}

void	print_s1(int m[13], char *n, int f)
{
	if (m[0] == 0)
		writeln(m[5] - m[6], ' ', m);
	if (f == 0)
		writes(n, m);
	else
		nulls(m);
	if (m[0] == 1)
		writeln(m[5] - m[6], ' ', m);
}

int		type_s(va_list *vl, int m[13])
{
	char	*n;

	n = va_arg(*vl, char *);
	print_s(m, n);
	return (0);
}
