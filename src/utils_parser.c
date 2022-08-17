/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:50:17 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/16 16:25:58 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\a')
		return (1);
	return (0);
}

void	free_array(char **array, t_map *m, int error)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		exit_func(m, 1, "no single exit\n");
	array = NULL;
}

char	*join_str(char *s1, char *s2)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
	{
		ft_strdel(&s1);
		ft_strdel(&new_s);
		return (s2);
	}
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	return (new_s);
}

void	read_flags(int argc, char **argv, t_map *m)
{
	int i;

	i = 1;
	while (argv[i][0] == '-' && i < argc)
	{
		if (ft_strequ(argv[i], "-m"))
			m->m = 1;
		else if (ft_strequ(argv[i], "-a"))
			m->a = 1;
		else if (ft_strequ(argv[i], "-e"))
			m->e = 1;
		else if (ft_strequ(argv[i], "-k"))
			m->k = 1;
		else if (ft_strequ(argv[i], "-w"))
			m->w = 1;
		else
			exit_func(m, 1, "invalid flag\n");
		if (!argv[++i])
			break ;
	}
}
