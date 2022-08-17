/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:55:47 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:55:48 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int			type_p(va_list *vl, int m[13])
{
	unsigned long int	n;
	char				a[21];
	int					k;

	n = (unsigned long int)(void*)va_arg(*vl, unsigned long int);
	m[10] = 1;
	m[3] = 2;
	di1(a);
	if (n)
		k = lxtoc(a, n, m);
	else
	{
		k = 3;
		nil(a);
		m[6] = 0;
	}
	if (m[6] >= k)
	{
		m[8] = k;
		k = 0;
	}
	print_lx(a, m, k, n);
	return (0);
}

void		nil(char a[21])
{
	a[20] = '0';
	a[19] = 'x';
	a[18] = '0';
}
