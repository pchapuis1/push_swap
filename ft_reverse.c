/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:59:25 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:16:06 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_nb *a, int len, int status)
{
	int	temp;
	int	i;

	if (status == 1)
		write(1, "rra\n", 4);
	i = len - 1;
	if (a[i].status == 0)
		return ;
	temp = a[i].nb;
	while (i > 0 && a[i - 1].status == 1)
	{
		a[i].nb = a[i - 1].nb;
		i --;
	}
	a[i].nb = temp;
}

void	ft_rrb(t_nb *b, int len, int status)
{
	int	temp;
	int	i;

	if (status == 1)
		write(1, "rrb\n", 4);
	i = len - 1;
	if (b[i].status == 0)
		return ;
	temp = b[i].nb;
	while (i > 0 && b[i - 1].status == 1)
	{
		b[i].nb = b[i - 1].nb;
		i --;
	}
	b[i].nb = temp;
}

void	ft_rrr(t_nb *a, t_nb *b, int nb)
{
	ft_rra(a, nb, 0);
	ft_rrb(b, nb, 0);
	write(1, "rrr\n", 4);
}
