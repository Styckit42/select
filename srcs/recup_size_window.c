/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_size_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 18:56:33 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/29 18:56:34 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_pos	*recup_size_window(t_pos *pos)
{
	struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    pos->nbr_l = w.ws_row;
    pos->nbr_c = w.ws_col;
    return (pos);
}