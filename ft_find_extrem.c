/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_extrem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:32:12 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:18:03 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_extrem	find_max(t_nb *b, int len)
{
	t_extrem	result;
	int			i;

	i = 0;
	while (b[i].status == 0)
		i ++;
	result.nb = b[i].nb;
	result.pos = i;
	while (i < len)
	{
		if (b[i].nb > result.nb)
		{
			result.nb = b[i].nb;
			result.pos = i;
		}
	i ++;
	}
	return (result);
}

t_extrem	find_min(t_nb *b, int len)
{
	t_extrem	result;
	int			i;

	i = 0;
	while (b[i].status == 0)
		i ++;
	result.nb = b[i].nb;
	result.pos = i;
	while (i < len)
	{
		if (b[i].nb < result.nb)
		{
			result.nb = b[i].nb;
			result.pos = i;
		}
	i ++;
	}
	return (result);
}

t_min	ft_min(t_extrem extrem, int i, int len)
{
	t_min	result;

	if (extrem.pos - i <= len - extrem.pos)
	{
		result.nb = extrem.pos - i;
		result.way = 'U';
	}
	else
	{
		result.nb = len - extrem.pos;
		result.way = 'D';
	}
	return (result);
}

int	ft_extract(t_min extrem, t_nb *b, int len)
{
	if (extrem.way == 'U')
		while (extrem.nb -- > 0)
			ft_rb(b, len, 1);
	else
		while (extrem.nb -- > 0)
			ft_rrb(b, len, 1);
	return (1);
}

t_sep	*find_sep(int len, int nb_sep)
{
	t_sep	*sep;
	int		tmp;
	int		i;

	i = 0;
	sep = malloc(sizeof(t_sep) * nb_sep);
	if (!sep)
		return (NULL);
	tmp = 0;
	while (i < nb_sep)
	{
		sep[i].start = tmp;
		tmp += len / nb_sep;
		if (i + 1 == nb_sep)
			sep[i].end = tmp + len % nb_sep;
		else
			sep[i].end = tmp;
		i ++;
	}
	return (sep);
}
