/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:22:40 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 13:04:15 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_nb *a, int nb, int status)
{
	int	tmp;
	int	i;

	if (status == 1)
		write(1, "sa\n", 3);
	i = 0;
	while (i < nb && a[i].status == 0)
		i ++;
	if (i == nb || i == nb - 1)
		return ;
	tmp = a[i].nb;
	a[i].nb = a[i + 1].nb;
	a[i + 1].nb = tmp;
}

void	ft_sb(t_nb *b, int nb, int status)
{
	int	tmp;
	int	i;

	if (status == 1)
		write(1, "sb\n", 3);
	i = 0;
	while (i < nb && b[i].status == 0)
		i ++;
	if (i == nb || i == nb - 1)
		return ;
	tmp = b[i].nb;
	b[i].nb = b[i + 1].nb;
	b[i + 1].nb = tmp;
}

void	ft_ss(t_nb *a, t_nb *b, int nb)
{
	ft_sa(a, nb, 0);
	ft_sb(b, nb, 0);
	write(1, "ss\n", 3);
}
