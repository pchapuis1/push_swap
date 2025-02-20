/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:48:51 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/18 18:26:33 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static void	define_status(t_nb *b, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		b[i].status = 0;
		i ++;
	}
}

static void	ft_grade(t_nb *a, int nb)
{
	int	i;
	int	x;
	int	min;
	int	min_pos;

	x = 0;
	while (x < nb)
	{
		i = 0;
		while (a[i].status == 1)
			i ++;
		min = a[i].nb;
		i = -1;
		while (++i < nb)
		{
			if (a[i].nb <= min && a[i].status == 0)
			{
				min = a[i].nb;
				min_pos = i;
			}
		}
		a[min_pos].nb = x;
		a[min_pos].status = 1;
		x ++;
	}
}

int	main(int argc, char **argv)
{
	int		nb;
	t_nb	*a;
	t_nb	*b;

	nb = nb_number(argc, argv);
	if (nb == -1)
		return (error());
	a = malloc(sizeof(t_nb) * nb);
	if (!a)
		return (error());
	if (ft_place(a, argv + 1, nb) == -1)
		return (free(a), error());
	if (check_double(a, nb) == 1)
		return (free(a), error());
	b = malloc(sizeof(t_nb) * nb);
	if (!b)
		return (free(a), error());
	define_status(b, nb);
	ft_grade(a, nb);
	if (sort(a, b, nb) == 1)
		error();
	free(a);
	free(b);
	return (0);
}
