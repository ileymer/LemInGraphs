/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:07:20 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:51:46 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		lfttoc(char t[100], long double n, long long r, int m[13])
{
	long long	k;
	int			p;
	int			j;

	j = 0;
	p = m[6];
	if (n < 0)
		n = n * (-1);
	k = (long long)n;
	n = n - (long double)(k);
	check_lf(m, r, n);
	while (p-- > 0 && j < 100)
	{
		n = n * 10;
		k = (long long)(n);
		if (j == 0 && k >= 5)
			m[10] = 1;
		t[j++] = k + '0';
		n = n - (long double)(k);
	}
	if ((int)(n * 10) >= 5)
		m[8] = fttoc1(t, --j);
	return (0);
}

void	print_lf(char t[100], int m[13], char a[21], long double n)
{
	if ((m[6] != 0 || m[7] == 0 || m[3] == 1) && (a[20] != 'i'))
		m[12] = 1;
	if (m[0] == 0)
	{
		if (m[4] == 1)
		{
			signlf(n, m[1], m[2], m);
			writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], ' ', m);
			signlf(n, m[1], m[2], m);
		}
	}
	if (m[0] == 1)
		signlf(n, m[1], m[2], m);
	print_d1(a, m);
	if (m[12] == 1)
		print_f1(t, m);
	writeln(m[6] - 100, '0', m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], ' ', m);
}

int		type_lf(va_list *vl, int m[13])
{
	long double		n;
	long long int	k;
	char			a[21];
	char			t[100];

	n = (va_arg(*vl, long double));
	di1(a);
	f1(t);
	if (-9223372036854775700.0 < n && n < 9223372036854775700.0)
	{
		if (m[6] == 0 && m[7] == 0)
			m[6] = 6;
		k = n;
		lfttoc(t, n, k, m);
		if (m[6] == 0 && m[7] == 1 && m[10] == 1)
			m[8]++;
		if (n < 0)
			m[8] = m[8] * (-1);
		m[9] = ftoc(a, k + m[8], m);
	}
	else
		pr_linf(m, a, n);
	print_lf(t, m, a, n);
	return (0);
}

int		lftoc(char a[21], long long int n, int m[13])
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (n < 0)
	{
		if (m[2] != 1)
			m[1] = 1;
		n = n * (-1);
	}
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	while (n > 0)
	{
		a[i++] = (n % 10) + '0';
		n = n / 10;
		k++;
	}
	return (k);
}
