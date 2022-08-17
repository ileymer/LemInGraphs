/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:48:07 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:51:59 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

void	type_b(va_list *vl, int m[13], int o)
{
	unsigned int	n;
	int				k;
	char			a[50];

	n = (unsigned int)va_arg(*vl, int);
	if (n == 0 && m[6] == 0 && m[7] == 1)
		m[10] = 1;
	b_mas(a);
	k = bon_toc(a, n, m, o);
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	if (m[10] == 1)
		k = 0;
	print_bon(a, m, k);
}

int		bon_toc(char a[50], unsigned int n, int m[13], int o)
{
	int k;
	int i;

	k = 0;
	i = 0;
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	while (n > 0)
	{
		a[i++] = paste_x(n % o, m[10]);
		n = n / o;
		k++;
	}
	if (k > m[6])
		m[6] = 0;
	return (k);
}

void	print_bon(char a[50], int m[8], int k)
{
	if (m[0] == 0)
	{
		if (m[4] == 1 && m[7] == 0)
		{
			writeln(m[5] - m[6] - m[1] - m[2] - k, '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[1] - m[2] - k, ' ', m);
		}
	}
	writeln(m[6] - k - m[8], '0', m);
	print_bon1(a, m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[1] - m[2] - k, ' ', m);
}

int		bon_flag(char c)
{
	if (c == 'b')
		return (2);
	else if (c == 'c')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'e')
		return (5);
	else if (c == 'f')
		return (6);
	else if (c == 'g')
		return (7);
	else if (c == 'h')
		return (8);
	else if (c == 'i')
		return (9);
	else if (c == 'j')
		return (10);
	else if (c == 'k')
		return (11);
	else if (c == 'l')
		return (12);
	else if (c == 'm')
		return (13);
	return (0);
}

int		distrib_b(int *i, char *f, int m[13], va_list *vl)
{
	int o;
	int ii;

	ii = *i;
	o = bon_flag(f[ii]);
	if (f[ii] == 'n')
		o = 14;
	else if (f[ii] == 'o')
		o = 15;
	else if (f[ii] == 'p')
		o = 16;
	if (o != 0)
		type_b(vl, m, o);
	return (0);
}
