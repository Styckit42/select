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


static void	len_lst(t_lst *lst, t_pos *pos)
{
	int cpt;
	t_lst	*tmp;

	tmp = lst;
	cpt = 0;
	while (tmp->next != pos->target)
	{
		cpt++;
		tmp = tmp->next;
	}
	cpt++;
	pos->nbr_elem = cpt;
}

static	void	len_biggest(t_lst *lst, t_pos *pos)
{
	t_lst	*tmp;

	tmp = lst;
	pos->lenest = ft_strlen(tmp->name);
	while (tmp->next != pos->target)
	{
		if (ft_strlen(tmp->name) > pos->lenest)
			pos->lenest = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	if (ft_strlen(tmp->name) > pos->lenest)
		pos->lenest = ft_strlen(tmp->name);
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
		len_lst(lst, &pos);
		len_biggest(lst, &pos);
		init_termios(&term);
		start_work(&term, &lst, &pos);
		restore_param(term);
	}
	return (0);
}