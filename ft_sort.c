/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:59:30 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/11 15:02:02 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_status(int i, int nb_split)
{
	if (i == 0)
		return (0);
	else if (i + 1 == nb_split)
		return (2);
	else if (i < 4)
		return (1);
	else
		return (-1);
}

static int	sort_b(t_nb *a, t_nb *b, int len, int nb)
{
	t_min	max;
	t_min	min;
	int		i;
	int		count;

	count = 0;
	while (nb -- > 0)
	{
		i = 0;
		while (b[i].status == 0)
			i ++;
		max = ft_min(find_max(b, len), i, len);
		min = ft_min(find_min(b, len), i, len);
		if (min.nb <= max.nb)
			ft_extract(min, b, len);
		else
			count += ft_extract(max, b, len);
		ft_pa(a, b, len);
		if (min.nb <= max.nb)
			ft_ra(a, len, 1);
	}
	return (count);
}

static int	sort_a(t_nb *a, t_nb *b, int len, int nb_split)
{
	t_limit	limit;
	int		count;
	int		i;
	t_sep	*sep;

	sep = find_sep(len, nb_split);
	if (!sep)
		return (1);
	i = 0;
	while (i < nb_split)
	{
		limit.max = sep[i].end;
		limit.min = sep[i].start;
		limit.status = ft_status(i, nb_split);
		if (i + 1 == nb_split)
			limit.nb = len / nb_split + len % nb_split;
		else
			limit.nb = len / nb_split;
		send_b(a, b, len, limit);
		count = sort_b(a, b, len, limit.nb);
		while (-- count >= 0)
			ft_ra(a, len, 1);
		i ++;
	}
	return (free(sep), 0);
}

int	sort(t_nb *a, t_nb *b, int nb)
{
	if (check_final_output(a, nb) == 1)
		return (0);
	if (nb <= 3)
		final_sort_3(a, nb);
	else if (nb <= 5)
		sort_5(a, b, nb);
	else if (nb <= 100)
	{
		if (sort_a(a, b, nb, 3) == 1)
			return (1);
	}
	else
	{
		if (sort_a(a, b, nb, 7) == 1)
			return (1);
	}
	return (0);
}
