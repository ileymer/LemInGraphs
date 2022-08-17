/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:53:58 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 12:07:01 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		type_ho(va_list *vl, int m[13])
{
	unsigned short int	n;
	int					k;
	char				a[50];

	m[1] = 0;
	n = (unsigned short)va_arg(*vl, int);
	if (n == 0 && m[6] == 0 && m[7] == 1)
		m[1] = 1;
	b_mas(a);
	k = hotoc(a, n, m);
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	if (m[1] == 1)
		k = 0;
	print_ho(a, m, k, n);
	return (0);
}

int		hotoc(char a[50], unsigned short int n, int m[13])
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	while (n > 0)
	{
		a[i++] = (n % 8) + '0';
		n = n / 8;
		k++;
	}
	if (k > m[6])
		m[6] = 0;
	return (k);
}

void	print_ho(char a[50], int m[13], int k, unsigned short int n)
{
	if (m[0] == 0)
	{
		if (m[4] == 1 && m[7] == 0)
		{
			signx(m[3], m[10], m, n);
			writeln(m[5] - m[6] - m[3] - k, '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[3] - k, ' ', m);
			signx(m[3], m[10], m, n);
		}
	}
	if (m[0] == 1)
		signx(m[3], m[10], m, n);
	writeln(m[6] - k - m[8], '0', m);
	print_bon1(a, m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[3] - k, ' ', m);
}
