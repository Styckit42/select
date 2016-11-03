/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 19:23:04 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/28 19:23:06 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		restore_param()
{
	struct termios term;
 
	if (tcgetattr(0, &term) == -1)
   		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
   		return (-1);
   	else
   		return (0);
}
