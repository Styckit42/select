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
	/*t_lst		*tmp;
	//_lst	*del;
	printf("target = %s\n", pos->target->name);
	if (current == pos->target)
		pos->target = lst->next;
	while (lst->next != current)
		lst = lst->next;
	tmp = lst->next->next;
	tmp->prev = lst;
	tmp->current = 1;
	//ft_strdel(lst->next->name);
	free(lst->next);
	pos->len--;*/
	
	t_lst	*tmp;

	(void)pos;
	while (lst->next != del)
		lst = lst->next;
	tmp = lst->next->next;
	tmp->prev = lst;
	free(del);
}

/*static void	erase_lst(t_lst *lst, t_pos *pos, t_lst *tmp)
{
	(void)lst;
	(void)tmp;
	(void)pos;
	free(tmp);
	exit (1);
}*/

/*static void	erase_first_elem(t_lst *lst, t_pos *pos, t_lst	*tmp)
{
	t_lst	*tmp2;

	while (tmp->next != pos->target)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp = tmp->next->next;
	pos->target = tmp->next->next;
	free(tmp2);
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}*/

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
