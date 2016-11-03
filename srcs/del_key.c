/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:59:02 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/31 17:59:03 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void del_maillon(t_lst *lst, t_pos *pos, t_lst *del)
{
	t_lst	*tmp;

	(void)pos;
	while (lst->next != del)
		lst = lst->next;
	tmp = lst->next->next;
	tmp->prev = lst;
	free(del);
}

void		del_key(t_lst *lst, t_pos *pos)
{
	t_lst	*current;

	current = lst;
	if (lst->next == lst)
	{
		free(lst);
		lst = NULL;
		exit (1);
	}
	/*else if (lst->current == 1)
		erase_first_elem(lst, pos, tmp);*/
	while (current->current != 1)
		current = current->next;
	if (current->current == 1)
		del_maillon(lst, pos, current);
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}	
