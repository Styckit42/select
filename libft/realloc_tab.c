/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:32:44 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/03 16:33:59 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**realloc_tab(char **tabl, char *str, int cpt)
{
	char	**dest;
	int		i;

	dest = (char **)malloc(sizeof(char *) * (cpt + 1) + 1);
	i = 0;
	while (i < cpt)
	{
		dest[i] = ft_strdup(tabl[i]);
		i++;
	}
	dest[i] = ft_strdup(str);
	dest[i + 1] = NULL;
	return (dest);
}
