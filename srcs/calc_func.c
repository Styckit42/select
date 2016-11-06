/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:26:10 by tcabon            #+#    #+#             */
/*   Updated: 2016/11/06 19:26:12 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t calc_lenest(t_lst *lst, t_pos *pos)
{
	unsigned int	ret;
	unsigned int	cpt;
	t_lst			*tmp;

	cpt = 0;
	ret = 0;
	tmp = lst;
	while (cpt <= (size_t)pos->nbr_l)
	{
		if (ft_strlen(tmp->name) > ret)
			ret = ft_strlen(tmp->name);
		tmp = tmp->next;
		cpt++;
	}
	return (ret);
}

size_t recalc_lenest(t_lst *lst, t_pos *pos, size_t index)
{
	unsigned int	ret;
	unsigned int	cpt;
	t_lst			*tmp;

	(void)pos;
	tmp = lst;
	ret = 0;
	cpt = 0;
	while(cpt < index)
	{
		if (ft_strlen(tmp->name) > ret)
			ret = ft_strlen(tmp->name);
		tmp = tmp->next;
		cpt++;
	}
	return (ret);
}
