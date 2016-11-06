/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:47:03 by tcabon            #+#    #+#             */
/*   Updated: 2016/11/06 17:47:04 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_resize(t_lst *lst, t_pos *pos)
{
	unsigned int	cpt;
	t_lst			*tmp;

	cpt = 0;
	tmp = lst;
	pos->lenest = calc_lenest(lst, pos);
	while (cpt <= (size_t)pos->nbr_l)
	{
		if (pos->lenest <= (size_t)pos->nbr_c)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
			cpt++;
		}
	}
	tputs(tgoto(tgetstr("cm", NULL), 0, pos->lenest + 2), 1, ft_puts);
	recalc_lenest(lst, pos, cpt);
	//print_next_col(tmp, pos, cpt);
}
