/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:53:06 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:53:07 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int	print_c(int m[13], char n)
{
	if (m[0] == 0)
	{
		if (m[4] == 1)
			writeln(m[5] - 1, ' ', m);
		else
			writeln(m[5] - 1, ' ', m);
	}
	writeln(1, n, m);
	if (m[0] == 1)
		writeln(m[5] - 1, ' ', m);
	return (0);
}

int	type_c(va_list *vl, int m[13])
{
	char	n;

	n = va_arg(*vl, int);
	print_c(m, n);
	return (0);
}
