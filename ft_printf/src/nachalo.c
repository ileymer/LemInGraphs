/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nachalo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:18:53 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:51:46 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		flag1(char c)
{
	if (c == '-' || c == ' ' || c == '+' || c == '#' || c == '0')
		return (1);
	return (0);
}

void	writeln(int n, char c, int m[13])
{
	while (n-- > 0)
	{
		write(1, &c, 1);
		m[11]++;
	}
}

void	nol(int m[13])
{
	int		i;

	i = 0;
	while (i < 13)
		m[i++] = 0;
}

void	di1(char a[21])
{
	int i;

	i = 0;
	while (i < 21)
		a[i++] = '.';
}

char	paste_x(unsigned int n, int f)
{
	char c;

	c = n + '0';
	if (n > 9)
	{
		if (n == 10)
			c = 'a';
		else if (n == 11)
			c = 'b';
		else if (n == 12)
			c = 'c';
		else if (n == 13)
			c = 'd';
		else if (n == 14)
			c = 'e';
		else if (n == 15)
			c = 'f';
		if (f == 2)
			return (c - 32);
		else
			return (c);
	}
	return (c);
}
