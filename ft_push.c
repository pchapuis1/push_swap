/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:03:55 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:16:23 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_nb *a, t_nb *b, int nb)
{
	int	i;
	int	j;

	write(1, "pa\n", 3);
	i = 0;
	while (i < nb && b[i].status == 0)
		i ++;
	if (i == nb)
		return ;
	j = 0;
	while (j < nb && a[j].status == 0)
		j ++;
	j --;
	a[j].nb = b[i].nb;
	b[i].status = 0;
	a[j].status = 1;
}

void	ft_pb(t_nb *b, t_nb *a, int nb)
{
	int	i;
	int	j;

	write(1, "pb\n", 3);
	i = 0;
	while (i < nb && a[i].status == 0)
		i ++;
	if (i == nb)
		return ;
	j = 0;
	while (j < nb && b[j].status == 0)
		j ++;
	j --;
	b[j].nb = a[i].nb;
	a[i].status = 0;
	b[j].status = 1;
}
