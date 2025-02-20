/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:25:31 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:15:38 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_nb *a, int nb, int status)
{
	int	temp;
	int	i;

	if (status == 1)
		write(1, "ra\n", 3);
	i = 0;
	while (i < nb && a[i].status == 0)
		i ++;
	if (i == nb)
		return ;
	temp = a[i].nb;
	while (i < nb - 1)
	{
		a[i].nb = a[i + 1].nb;
		i ++;
	}
	a[i].nb = temp;
}

void	ft_rb(t_nb *b, int nb, int status)
{
	int	temp;
	int	i;

	if (status == 1)
		write(1, "rb\n", 3);
	i = 0;
	while (i < nb && b[i].status == 0)
		i ++;
	if (i == nb)
		return ;
	temp = b[i].nb;
	while (i < nb - 1)
	{
		b[i].nb = b[i + 1].nb;
		i ++;
	}
	b[i].nb = temp;
}

void	ft_rr(t_nb *a, t_nb *b, int nb)
{
	ft_ra(a, nb, 0);
	ft_rb(b, nb, 0);
	write(1, "rr\n", 3);
}
