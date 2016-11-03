/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_select.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:20:54 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/25 20:21:33 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <term.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

# define UP "27[A"
# define DOWN 1346525979
# define RIGHT 1346591515
# define LEFT 1346657051

typedef struct		s_lst
{
	char			*name;
	int				current;
	int				select;
	struct	s_lst	*prev;
	struct	s_lst	*next;
}					t_lst;

typedef struct		s_pos
{
	short int		nbr_l;
	short int		nbr_c;
	struct	s_lst	*target;
	int				len;
}					t_pos;

t_lst				*argv_to_lst(char **argv, int argc, t_pos *pos);
void				arrow_key(struct termios *term, t_lst *lst, t_pos *pos, char *buffer);
void				del_func(t_lst **lst, t_pos *pos);
void				del_key(t_lst *lst, t_pos *pos);
int 				event_func(struct termios *term, t_lst **lst, t_pos *pos);
int					ft_puts(int c);
int					init_termios(struct termios *term);
void				other_key(struct termios *term, t_lst **lst, t_pos *pos, char *buffer);
void				print_list(t_lst *lst, t_pos *pos);
void				restore_param();
t_pos				*recup_size_window(t_pos *pos);
void				start_work(struct termios *term, t_lst **lst, t_pos *pos);


#endif