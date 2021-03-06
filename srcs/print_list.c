/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 21:26:35 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/29 21:26:36 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_list(t_lst *lst, t_pos *pos)
{
	lst = pos->target;
	while(lst->next != pos->target)
	{
		if (lst->current == 1)
			tputs(tgetstr("us", NULL), 1, ft_puts);
		if (lst->select == 1)
			tputs(tgetstr("mr", NULL), 1, ft_puts);
		ft_putendl(lst->name);
		tputs(tgetstr("me", NULL), 1, ft_puts);
		lst = lst->next;
	}
	if (lst->current == 1)
	{
		tputs(tgetstr("us", NULL), 1, ft_puts);
		if (lst->select == 1)
			tputs(tgetstr("mr", NULL), 1, ft_puts);
		ft_putendl(lst->name);
		tputs(tgetstr("me", NULL), 1, ft_puts);
	}
	else
	{
		if (lst->select == 1)
			tputs(tgetstr("mr", NULL), 1, ft_puts);
		ft_putendl(lst->name);
		tputs(tgetstr("me", NULL), 1, ft_puts);
	}
	printf("biggest = %d\n", pos->lenest);
}

void	print_list2(t_lst *lst, t_pos *pos)
{
 	recup_size_window(pos);
 	if ((pos->nbr_elem <= (size_t)pos->nbr_l) && (pos->lenest <= (size_t)pos->nbr_c))
 		print_list(lst, pos);
 	else
 	{
 		printf("need resize\n");
 		print_resize(lst, pos);
 	}
}