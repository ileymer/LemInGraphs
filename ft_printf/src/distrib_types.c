/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:37:28 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:51:46 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		dioux(va_list *vl, int m[13], char f)
{
	if (f == 'd' || f == 'i')
		return (type_di(vl, m));
	else if (f == 'o')
		return (type_o(vl, m));
	else if (f == 'u')
		return (type_u(vl, m));
	else if (f == 'x' || f == 'X')
	{
		if (f == 'X')
			m[10] = 2;
		return (type_x(vl, m));
	}
	return (0);
}

int		csp(va_list *vl, int m[13], char f)
{
	if (f == 'c')
		return (type_c(vl, m));
	else if (f == 's')
		return (type_s(vl, m));
	else if (f == 'p')
		return (type_p(vl, m));
	return (0);
}

int		hlb(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'b')
	{
		*i = ++ii;
		return (distrib_b(i, f, m, vl));
	}
	else if (f[ii] == 'l')
	{
		*i = ++ii;
		return (distrib_l(i, f, m, vl));
	}
	else if (f[ii] == 'L')
	{
		*i = ++ii;
		return (distrib_lf(i, f, m, vl));
	}
	else if (f[ii] == 'h')
	{
		ii++;
		*i = ii;
		return (distrib_h(i, f, m, vl));
	}
	return (0);
}
