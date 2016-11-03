/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 22:32:35 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/29 22:32:37 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		space_key(t_lst *lst, t_pos *pos)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp->current != 1)
		tmp = tmp->next;
	if (tmp->current == 1 && tmp->select == 0)
	{
		tmp->select = 1;
		tmp->current = 0;
		tmp->next->current = 1;
	}
	else if (tmp->current == 1 && tmp->select == 1)
	{
		tmp->select = 0;
		tmp->current = 0;
		tmp->next->current = 1;
	}
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	print_list(lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
}

void			other_key(struct termios *term, t_lst **lst, t_pos *pos, char *buffer)
{
	(void)lst;
	(void)pos;
	(void)term;
	printf("buffer[0] = %d, buffer[1] = %d, buffer[3] = %d\n", buffer[0], buffer[1], buffer[2]);
	if (buffer[0] == 32)
		space_key(*lst, pos);
	else if (buffer[0] == 126 || buffer[0] == 127)
		del_func(lst, pos);
	else if (buffer[0] == 10)
		valide_choice(lst, pos);
}
