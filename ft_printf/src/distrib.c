/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:52:39 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:52:41 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		distrib_ll(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'd' || f[ii] == 'i')
		return (type_lldi(vl, m));
	else if (f[ii] == 'x' || f[ii] == 'X')
	{
		if (f[ii] == 'X')
			m[10] = 2;
		type_llx(vl, m);
	}
	else if (f[ii] == 'o')
		return (type_llo(vl, m));
	else if (f[ii] == 'u')
		return (type_llu(vl, m));
	return (0);
}

int		distrib_l(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'd' || f[ii] == 'i')
		return (type_ldi(vl, m));
	if (f[ii] == 'x' || f[ii] == 'X')
	{
		if (f[ii] == 'X')
			m[10] = 2;
		type_lx(vl, m);
	}
	else if (f[ii] == 'o')
		return (type_lo(vl, m));
	else if (f[ii] == 'u')
		return (type_lu(vl, m));
	else if (f[ii] == 'f')
		return (type_f(vl, m));
	else if (f[ii] == 'l')
	{
		ii++;
		*i = ii;
		return (distrib_ll(i, f, m, vl));
	}
	return (0);
}

int		distrib_hh(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'd' || f[ii] == 'i')
		return (type_hhdi(vl, m));
	else if (f[ii] == 'x' || f[ii] == 'X')
	{
		if (f[ii] == 'X')
			m[10] = 2;
		type_hhx(vl, m);
	}
	else if (f[ii] == 'o')
	{
		type_hho(vl, m);
	}
	else if (f[ii] == 'u')
		type_hhu(vl, m);
	return (0);
}

int		distrib_h(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (f[ii] == 'd' || f[ii] == 'i')
		return (type_hdi(vl, m));
	else if (f[ii] == 'x' || f[ii] == 'X')
	{
		if (f[ii] == 'X')
			m[10] = 2;
		type_hx(vl, m);
	}
	if (f[ii] == 'o')
		return (type_ho(vl, m));
	else if (f[ii] == 'u')
		type_hu(vl, m);
	else if (f[ii] == 'h')
	{
		ii++;
		*i = ii;
		return (distrib_hh(i, f, m, vl));
	}
	return (0);
}

int		distrib_types(int *i, char *f, int m[13], va_list *vl)
{
	int ii;

	ii = *i;
	if (check_dioux(f[ii]))
		return (dioux(vl, m, f[ii]));
	else if (check_csp(f[ii]))
		return (csp(vl, m, f[ii]));
	else if (check_hlb(f[ii]))
		hlb(i, f, m, vl);
	else if (f[ii] == '%')
		writeln(1, '%', m);
	else if (f[ii] == 'f')
		type_f(vl, m);
	else if (f[ii] != '\0')
	{
		write(1, &f[ii], 1);
		m[11]++;
	}
	else
	{
		write(1, &f[ii - 1], 1);
		m[11]++;
	}
	return (0);
}
