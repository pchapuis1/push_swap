/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:08:35 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/11 15:00:16 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort_3(t_nb *a, int nb)
{
	if (nb == 1)
		return ;
	else if (nb == 2)
		ft_sa(a, nb, 1);
	else
	{
		while (check_final_output(a, nb) == 0)
		{
			if (a[0].nb > a[1].nb)
				ft_sa(a, nb, 1);
			if (check_final_output(a, nb) == 0)
				ft_rra(a, nb, 1);
		}
	}
}

static void	sort_3(t_nb *a, int len, int nb)
{
	int	i;

	if (check_increase(a, len) == 0 && nb == 2)
		ft_sa(a, len, 1);
	else if (nb == 3)
	{
		while (check_increase(a, len) == 0)
		{	
			i = 0;
			while (a[i].status == 0)
				i ++;
			if (a[i].nb > a[i + 1].nb)
				ft_sa(a, len, 1);
			if (check_increase(a, len) == 0)
				ft_rra(a, len, 1);
		}
	}
}

static int	sort_3_rev(t_nb *a, t_nb *b, int len, int nb)
{
	int	i;
	int	x;

	if (check_decrease(b, len) == 0 && nb == 2)
		ft_sb(b, len, 1);
	else if (nb == 3)
	{
		while (check_decrease(b, len) == 0)
		{
			i = 0;
			while (b[i].status == 0)
				i ++;
			if (b[i].nb < b[i + 1].nb)
				ft_sb(b, len, 1);
			if (check_decrease(b, len) == 0)
				ft_rrb(b, len, 1);
		}
	}
	i = 0;
	x = 0;
	while (b[i].status == 0)
		i ++;
	while (i + x++ < len)
		ft_pa(a, b, len);
	return (x);
}

void	sort_5(t_nb *a, t_nb *b, int len)
{
	t_limit	limit;

	limit.max = ft_median(a, len, len);
	limit.min = 0;
	limit.nb = 2;
	send_b(a, b, len, limit);
	sort_3(a, len, len - 2);
	sort_3_rev(a, b, len, 2);
}
