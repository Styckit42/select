/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 18:27:39 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/28 18:27:41 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		start_work(struct termios *term, t_lst **lst, t_pos *pos)
{
	(void)term;
	pos = recup_size_window(pos);
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	tputs(tgetstr("ti", NULL), 1, ft_puts);

	print_list(*lst, pos);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_puts);
	event_func(term, lst, pos);
}
