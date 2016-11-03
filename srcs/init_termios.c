/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:24:20 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/26 17:24:24 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	int	modif_value(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (1);
}

int		init_termios(struct termios *term)
{
	char			*name_term;

 	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	modif_value(term);
	return (1);
}
