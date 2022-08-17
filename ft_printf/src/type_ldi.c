/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:54:25 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:54:26 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		litoc(char a[21], long int n, int m[13])
{
	int k;
	int i;

	k = 0;
	i = 0;
	if (n < 0)
		if (m[2] != 1)
			m[1] = 1;
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	while (n != 0)
	{
		if (n > 0)
			a[i++] = (n % 10) + '0';
		else
			a[i++] = ((n % 10) * (-1)) + '0';
		n = n / 10;
		k++;
	}
	if (k > m[6])
		m[6] = 0;
	return (k);
}

int		type_ldi(va_list *vl, int m[13])
{
	long int				n;
	char					a[21];
	int						k;

	n = va_arg(*vl, long int);
	if (n == 0 && m[6] == 0 && m[7] == 1)
		m[10] = 1;
	di1(a);
	k = litoc(a, n, m);
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	if (m[10] == 1)
		k = 0;
	print_ldi(a, m, k, n);
	return (k);
}

void	print_ldi(char a[15], int m[8], int k, long int n)
{
	if (m[0] == 0)
	{
		if (m[4] == 1 && m[7] == 0)
		{
			signldi(n, m[1], m[2], m);
			writeln(m[5] - m[6] - m[1] - m[2] - k, '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[1] - m[2] - k, ' ', m);
			signldi(n, m[1], m[2], m);
		}
	}
	if (m[0] == 1)
		signldi(n, m[1], m[2], m);
	writeln(m[6] - k - m[8], '0', m);
	print_di1(a, m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[1] - m[2] - k, ' ', m);
}

void	signldi(long int n, int f1, int f2, int m[13])
{
	if (n < 0)
	{
		write(1, "-", 1);
		m[11]++;
	}
	else
	{
		if (f1 == 1)
		{
			write(1, "+", 1);
			m[11]++;
		}
		if (f2 == 1)
		{
			write(1, " ", 1);
			m[11]++;
		}
	}
}
