/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:56:04 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:56:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		utoc(char a[21], unsigned int n, int m[13])
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

int		type_u(va_list *vl, int m[13])
{
	char			a[21];
	int				k;
	unsigned int	n;

	n = (unsigned int)va_arg(*vl, int);
	if (n == 0 && m[6] == 0 && m[7] == 1)
		m[10] = 1;
	di1(a);
	k = utoc(a, n, m);
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	if (m[10] == 1)
		k = 0;
	print_u(a, m, k);
	return (k);
}

void	print_u(char a[15], int m[8], int k)
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
	print_di1(a, m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[1] - m[2] - k, ' ', m);
}
