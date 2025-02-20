/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:26:05 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/18 16:35:55 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_nb *a, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (a[i].nb == a[j].nb)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i ++;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i ++;
	}
	return (1);
}

int	check_space(int nb)
{
	if (nb == 0)
		return (-1);
	else
		return (nb);
}
