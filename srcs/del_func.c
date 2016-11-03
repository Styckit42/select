/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:34:13 by tcabon            #+#    #+#             */
/*   Updated: 2016/11/01 18:34:17 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	erase_item(t_lst *lst, t_pos *pos, t_lst *del)
{
	t_lst *tmp;

	(void)pos;
	while (lst->next != del)
		lst = lst->next;
	tmp = del->next;
	lst->next = tmp;
	tmp->prev = lst;
	tmp->current = 1;
	ft_strdel(&(del)->name);
	free(del);
}

static void	delete_first_item(t_lst **lst, t_pos *pos, t_lst *del)
{
	t_lst	*old_lst;

	old_lst = *lst;
	pos->target = (*lst)->next;
	//tmp = del->next;
	
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	(*lst) = (*lst)->next;
	(*lst)->current = 1;
	ft_strdel(&(del)->name);
	free(del);
}

void		del_func(t_lst **lst, t_pos *pos)
{
	(void)pos;
	t_lst		*del;

	del = *lst;
	if (del->next == del)
	{
		ft_strdel(&(del)->name);
		free(del);
		exit(1);
	}
	if (del->current == 1)
		delete_first_item(lst, pos, del);
	else
	{
		while (del->current != 1)
		{
			del = del->next;
		}
		erase_item(*lst, pos, del);
	}
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(*lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}
