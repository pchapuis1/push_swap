/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:18 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:17:07 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *tab, int size)
{
	int	x;
	int	nb;

	nb = 0;
	while (nb < (size - 1))
	{
		if (tab[nb] > tab[nb + 1])
		{
			x = tab [nb];
			tab [nb] = tab [nb + 1];
			tab [nb + 1] = x;
			nb = 0;
		}
		else
			nb ++;
	}
}

int	ft_median(t_nb *a, int nb, int len)
{
	int	*tmp;
	int	i;
	int	x;
	int	median;

	tmp = malloc(sizeof(int) * nb);
	if (!tmp)
		return (-1);
	i = 0;
	while (a[i].status == 0)
		i ++;
	x = 0;
	while (i < len)
	{
		tmp[x] = a[i].nb;
		i ++;
		x ++;
	}
	ft_sort(tmp, nb);
	median = tmp[nb / 2];
	free(tmp);
	return (median);
}
