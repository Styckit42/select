/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:25:25 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/03 17:25:28 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *next_lst;

	lst = *alst;
	while (lst)
	{
		next_lst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = next_lst;
	}
	*alst = NULL;
}
