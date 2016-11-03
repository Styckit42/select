#include "ft_select.h"

static int	calc_cpt(t_lst **lst, t_pos *pos)
{
	int cpt;
	t_lst	*tmp;

	tmp = (*lst);
	cpt = 0;
	while(tmp->next != pos->target)
	{
		if (tmp->select == 1)
			cpt++;
		tmp = tmp->next;
	}
	if (tmp->select == 1)
		cpt++;
	return (cpt);
}

void		valide_choice(t_lst **lst, t_pos *pos)
{
	t_lst *tmp;
	tmp = (*lst);
	int		cpt;

	cpt = calc_cpt(lst, pos);
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	while (tmp->next != pos->target)
	{
		if (tmp->select == 1 && cpt > 1)
		{
			ft_putstr(tmp->name);
			ft_putchar(' ');
			cpt--;
		}
		tmp = tmp->next;
	}
	if (tmp->select == 1 && cpt == 1)
	{
		ft_putstr(tmp->name);
		ft_putchar('\n');
	}
	exit(1);
}