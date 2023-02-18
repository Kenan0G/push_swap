/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:33 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 19:44:52 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_init
{
	char	**str;
	int		check;
	int		*ptr;
	int		nb;
	int		*tab;
	int		tab_len;
	int		mediane;
	int		plus_grand;
	int		pos;
	int		index;
	int		index_a;
	int		index_b;
	int		k;
}				t_init;

void	print_list(t_list *lst);

t_list	*my_lstnew(int nb);
void	my_lstadd_back(t_list **lst, t_list *new);

int		my_atoi(char *nptr, int *check);
char	*my_atoi_utils(char	*str, int *sign, int **check);

void	init_init(t_init *init);
t_list	*init(int ac, char **av, t_init *init);
void	init_tab(t_list *lst_a, t_list *lst_b, t_init *init);
void	my_sort_int_tab(int *tab, int size);

void	put_top_a(t_list **lst, int content);
void	put_top_b(t_list **lst, int content);
void	tri_2(t_list **lst_a);
int		tri_3(t_list **lst_a, t_init *init);
int		tri_5(t_list **lst_a, t_list **lst_b, t_init *init);

void	algo(t_list **lst_a, t_list **lst_b, t_init *init);
void	tri(t_list **lst_a, t_list **lst_b, t_init *init);
void	pre_tri(t_list **lst_a, t_list **lst_b, t_init *init);
void	tri_final(t_list **lst, t_init *init);

int		calculator(t_list **lst_x, t_list **lst_y, t_init *init);
void	calculator_utils(t_list **lst_x, t_list **lst_y, t_init *init);
int		calcul_top(t_list *lst, t_init *init);
int		find_sup(t_list *lst, int nb);
int		get_pos(t_list *lst, int content);

int		check_doublon(t_list *lst);
int		check_tri(t_list *lst);
int		ft_check(t_list **lst);
void	ft_check_vide_and_my_atoi(t_init *init, t_list **lst, int d, int j);

void	push(t_list **lst_a, t_list **lst_b, char w);
void	swap(t_list **lst, char w);
void	ss(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst, char w);
void	rr(t_list **lst_a, t_list **lst_b);

void	r_rotate(t_list **lst, char w);
void	rrr(t_list **lst_a, t_list **lst_b);

void	ft_free_list(t_list **lst);
void	ft_free_map(char **str);
void	ft_free_1(char **str, t_list **lst);

#endif