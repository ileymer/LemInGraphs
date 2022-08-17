/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:18:39 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/16 12:25:51 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_element_end_queue(int data, t_queue *head, int f)
{
	t_queue		*tmp;
	t_queue		*p;

	p = head;
	tmp = (t_queue *)malloc(sizeof(t_queue));
	tmp->v = data;
	tmp->next = NULL;
	tmp->f = f;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = tmp;
}

int			check_queue(int data, t_queue *head)
{
	t_queue		*p;

	p = head;
	while (p != NULL)
	{
		if (p->v == data)
			return (0);
		p = p->next;
	}
	return (1);
}

t_queue		*remove_element(t_queue *head)
{
	t_queue *tmp;

	tmp = head->next;
	if (head == NULL)
		return (NULL);
	free(head);
	return (tmp);
}

int			remove_element_c(t_queue *head)
{
	t_queue *tmp;

	tmp = head->next;
	if (tmp->next != NULL)
		return (0);
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	free(tmp->next->next);
	tmp->next = NULL;
	return (0);
}
