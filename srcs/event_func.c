/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 20:31:42 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/29 20:31:43 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int 			event_func(struct termios *term, t_lst **lst, t_pos *pos)
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		//printf("buffer[0] = %d, buffer[1] = %d, buffer[3] = %d\n", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 27)
			arrow_key(term, *lst, pos, buffer);
		else
			other_key(term, lst, pos, buffer);
	}
	return (0);
}