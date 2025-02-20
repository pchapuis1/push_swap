/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:29:31 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/14 14:18:51 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_final_output(t_nb *a, int nb)
{
	int	i;

	i = 0;
	while (i < nb - 1)
	{
		if (a[i].nb > a[i + 1].nb || a[i].status == 0)
			return (0);
		i ++;
	}
	return (1);
}

int	check_increase(t_nb *a, int nb)
{
	int	i;

	i = 0;
	while (i < nb && a[i].status == 0)
		i ++;
	if (i != nb)
	{
		while (i < nb - 1)
		{
			if (a[i].nb > a[i + 1].nb)
				return (0);
			i ++;
		}
	}
	return (1);
}

int	check_decrease(t_nb *b, int nb)
{
	int	i;

	i = 0;
	while (i < nb && b[i].status == 0)
		i ++;
	if (i == nb)
		return (1);
	if (i != nb)
	{
		while (i < nb - 1)
		{
			if (b[i].nb < b[i + 1].nb)
				return (0);
			i ++;
		}
	}
	return (1);
}

int	check_output(t_nb *a, t_nb *b, int nb)
{
	int	i;
	int	j;

	if (check_increase(a, nb) == 0 || check_decrease(b, nb) == 0)
		return (0);
	i = 0;
	while (i < nb && a[i].status == 0)
		i ++;
	j = 0;
	while (j < nb && b[j].status == 0)
		j ++;
	if (a[i].nb < b[j].nb && i != nb && j != nb)
		return (0);
	return (1);
}
