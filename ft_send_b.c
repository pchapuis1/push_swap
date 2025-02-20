/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:59:58 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/11 14:59:13 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_back(t_nb *a, int len, t_limit limit, int i)
{
	if (limit.status == 1)
		while (i ++ < len)
			ft_ra(a, len, 1);
	else if (limit.status == -1)
		while (a[len - 1].nb != limit.min - 1)
			ft_rra(a, len, 1);
}

void	send_b(t_nb *a, t_nb *b, int len, t_limit limit)
{
	int	x;
	int	i;
	int	count;

	x = 0;
	count = 0;
	while (x < limit.nb)
	{
		i = 0;
		while (a[i].status == 0)
			i ++;
		if (a[i].nb < limit.max && a[i].nb >= limit.min)
		{
			ft_pb(b, a, len);
			x ++;
		}
		else
		{
			ft_ra(a, len, 1);
			count ++;
		}
	}
	rotate_back(a, len, limit, count + x);
}
