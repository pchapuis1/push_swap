/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:42:21 by pchapuis          #+#    #+#             */
/*   Updated: 2023/01/18 14:26:45 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_nb
{
	int	nb;
	int	status;
}	t_nb;

typedef struct s_extrem
{
	int	nb;
	int	pos;
}	t_extrem;

typedef struct s_min
{
	int		nb;
	char	way;
}	t_min;

typedef struct s_limit
{
	int	max;
	int	min;
	int	nb;
	int	status;
}	t_limit;

typedef struct s_sep
{
	int	start;
	int	end;
}	t_sep;

int			nb_number(int argc, char **argv);
int			check_double(t_nb *a, int nb);
int			is_space(char *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(char *str);
int			check_atoi(char *str);
int			ft_place(t_nb *a, char **argv, int nb);
void		ft_pa(t_nb *a, t_nb *b, int nb);
void		ft_pb(t_nb *b, t_nb *a, int nb);
void		ft_rra(t_nb *a, int nb, int status);
void		ft_rrb(t_nb *b, int nb, int status);
void		ft_rrr(t_nb *a, t_nb *b, int nb);
void		ft_ra(t_nb *a, int nb, int status);
void		ft_rb(t_nb *b, int nb, int status);
void		ft_rr(t_nb *a, t_nb *b, int nb);
void		ft_sa(t_nb *a, int nb, int status);
void		ft_sb(t_nb *b, int nb, int status);
void		ft_ss(t_nb *a, t_nb *b, int nb);
int			check_final_output(t_nb *a, int nb);
int			check_output(t_nb *a, t_nb *b, int nb);
int			check_increase(t_nb *a, int nb);
int			check_decrease(t_nb *b, int nb);
int			sort(t_nb *a, t_nb *b, int nb);
int			ft_median(t_nb *a, int nb, int len);
void		final_sort_3(t_nb *a, int nb);
void		sort_5(t_nb *a, t_nb *b, int len);
t_extrem	find_max(t_nb *b, int len);
t_extrem	find_min(t_nb *b, int len);
void		send_b(t_nb *a, t_nb *b, int len, t_limit limit);
int			ft_extract(t_min extrem, t_nb *b, int len);
t_sep		*find_sep(int len, int nb_sep);
t_min		ft_min(t_extrem extrem, int i, int len);
void		send_b(t_nb *a, t_nb *b, int len, t_limit limit);
int			is_number(char *str);

#endif