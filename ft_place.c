/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:49:10 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/11 14:58:06 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i ++;
	}
}

static int	ft_place_str(t_nb *a, char *str, int i)
{
	char	**temp;
	int		x;

	temp = ft_split(str, ' ');
	if (!temp)
		return (-1);
	x = 0;
	while (temp[x] != NULL)
	{
		if (check_atoi(temp[x]) == -1)
			return (free_split(temp), free(temp), -1);
		a[i].nb = ft_atoi(temp[x]);
		a[i].status = 0;
		i ++;
		x ++;
	}
	free_split(temp);
	free(temp);
	return (x);
}

int	ft_place(t_nb *a, char **argv, int nb)
{
	int		i;
	int		x;
	int		temp;

	i = 0;
	x = 0;
	while (i < nb)
	{
		if (is_space(argv[x]) == 0)
		{
			if (check_atoi(argv[x]) == -1)
				return (-1);
			a[i].status = 0;
			a[i ++].nb = ft_atoi(argv[x ++]);
		}
		else
		{
			temp = ft_place_str(a, argv[x], i);
			if (temp == -1)
				return (-1);
			i += temp;
			x ++;
		}
	}
	return (0);
}
