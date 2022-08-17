/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hhx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:53:49 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:53:52 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		type_hhx(va_list *vl, int m[13])
{
	char					a[21];
	unsigned char			n;
	int						k;

	m[1] = 0;
	n = (unsigned char)va_arg(*vl, int);
	if (n == 0 && m[6] == 0 && m[7] == 1)
		m[1] = 1;
	di1(a);
	k = hhxtoc(a, n, m);
	if (m[3] == 1)
		m[3] = 2;
	if (n == 0)
		m[3] = 0;
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	if (m[1] == 1)
		k = 0;
	print_hhx(a, m, k, n);
	return (0);
}

void	signhhx(int f, int f1, int m[13], unsigned char n)
{
	if (n != 0)
		if (f == 2)
		{
			write(1, "0", 1);
			m[11]++;
			if (f1 == 2)
			{
				write(1, "X", 1);
				m[11]++;
			}
			else
			{
				write(1, "x", 1);
				m[11]++;
			}
		}
	if (f == 1)
	{
		write(1, "0", 1);
		m[11]++;
	}
}

void	print_hhx(char a[15], int m[8], int k, unsigned char n)
{
	if (m[0] == 0)
	{
		if (m[4] == 1 && m[7] == 0)
		{
			signhhx(m[3], m[10], m, n);
			writeln(m[5] - m[6] - m[3] - k, '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[3] - k, ' ', m);
			signhhx(m[3], m[10], m, n);
		}
	}
	if (m[0] == 1)
		signhhx(m[3], m[10], m, n);
	writeln(m[6] - k - m[8], '0', m);
	print_x1(a, m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[3] - k, ' ', m);
}

int		hhxtoc(char a[21], unsigned char n, int m[13])
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	if (m[9] == 0)
		while (n > 0)
		{
			a[i++] = paste_x(n % 16, m[10]);
			n = n / 16;
			k++;
		}
	if (k > m[6])
		m[6] = 0;
	return (k);
}
