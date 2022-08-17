/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:50:34 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/30 10:51:46 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printlib.h"

int		check_dioux(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		check_csp(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}

int		check_hlb(char c)
{
	if (c == 'l' || c == 'h' || c == 'L' || c == 'b')
		return (1);
	return (0);
}

int		print_slash(void)
{
	write(1, "\\", 1);
	return (1);
}

void	fun_m(int m[13])
{
	m[4] = 0;
	m[0] = 1;
}
