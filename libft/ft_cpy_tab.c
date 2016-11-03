/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:26:20 by tcabon            #+#    #+#             */
/*   Updated: 2016/10/03 17:26:21 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_cpy_tab(char **tabl)
{
	unsigned int	i;
	char			**dest;

	i = 0;
	dest = (char**)malloc(sizeof(char*) * ft_len_tab(tabl) + 1);
	while (tabl[i])
	{
		dest[i] = ft_strdup(tabl[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
