/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 21:43:09 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/29 21:43:10 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	arrow_down(struct termios *term, t_lst *lst, t_pos *pos)
{
	(void)term;
	lst = pos->target;
	while(lst->current != 1)
		 lst = lst->next;
	lst->current = 0;
	lst = lst->next;
	lst->current = 1;
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}

static void	arrow_up(struct termios *term, t_lst *lst, t_pos *pos)
{
	(void)term;
	lst = pos->target;
	while(lst->current != 1)
		 lst = lst->next;
	lst->current = 0;
	lst = lst->prev;
	lst->current = 1;
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}

void		arrow_key(struct termios *term, t_lst *lst, t_pos *pos, char *buffer)
{
	(void)lst;
	(void)pos;
	(void)term;
	if (buffer[2] == 'A')
		arrow_up(term, lst, pos);
	else if (buffer[2] == 'B')
		arrow_down(term, lst, pos);
}
