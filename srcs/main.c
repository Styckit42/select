/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:23:43 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/25 20:24:01 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	new_lst(t_pos *pos)
{
	pos->target = NULL;
	pos->len = 0;
}


int			main(int argc, char **argv)
{
	t_lst				*lst;
	t_pos				pos;
	struct	termios		term;

	lst = NULL;
	new_lst(&pos);
	if (argc > 1)
	{
		lst = argv_to_lst(argv, argc, &pos);
		init_termios(&term);
		start_work(&term, &lst, &pos);
		restore_param();
	}
	return (0);
}