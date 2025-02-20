/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:06 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/18 18:15:16 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

static int	nb_split(char *argv)
{
	int		nb;
	int		j;
	char	**tmp;

	nb = 0;
	tmp = ft_split(argv, ' ');
	if (!tmp)
		return (-1);
	j = 0;
	while (tmp[j] != NULL)
	{
		if (is_number(tmp[j]) == 1)
			nb ++;
		else
			return (free_split(tmp), -1);
		j ++;
	}
	if (j == 0)
		return (free_split(tmp), -1);
	free_split(tmp);
	return (nb);
}

int	nb_number(int argc, char **argv)
{
	int	nb;
	int	i;
	int	tmp;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		if (is_space(argv[i]) == 0)
		{
			if (is_number(argv[i]) == 1)
				nb ++;
			else
				return (-1);
		}
		else
		{
			tmp = nb_split(argv[i]);
			if (tmp == -1)
				return (-1);
			nb += tmp;
		}
		i ++;
	}
	return (nb);
}
