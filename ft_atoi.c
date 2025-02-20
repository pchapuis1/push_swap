/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:11:00 by pchapuis          #+#    #+#             */
/*   Updated: 2022/12/01 16:40:46 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_atoi(char *str)
{
	long long int	result;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i ++;
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (-1);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long long int	result;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i ++;
	}
	return (result * sign);
}
