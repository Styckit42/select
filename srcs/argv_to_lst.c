/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:27:24 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/26 17:27:26 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_lst *add_to_list(t_lst *lst, char *str, t_pos *pos)
{
	t_lst	*elem;
	t_lst	*tmp;

	elem = malloc(sizeof(t_lst));
	elem->name = ft_strdup(str);
	elem->current = 0;
	elem->select = 0;
	elem->next = elem;
	elem->prev = elem;
	pos->len++;
	if (lst == NULL)
	{
		elem->current = 1;
		pos->target = elem;
		return (elem);
	}
	tmp = lst;
	while (tmp->next != pos->target)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = lst;
	elem->prev = tmp;
	lst->prev = elem;
	return (lst);
}


t_lst			*argv_to_lst(char **argv, int argc, t_pos *pos)
{
	t_lst	*lst;
	int	i;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		lst = add_to_list(lst, argv[i], pos);
		i++;
	}
	return (lst);
}
