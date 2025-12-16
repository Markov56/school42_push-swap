/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:25:01 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/16 19:43:11 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				current_index;
	int				sorted_index;
	int				target_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

int			validate_input(char **args);
int			ft_strcmp(char *str1, char *str2);
void		ft_putstr(char *s);
long int	ft_atoi(const char *str);
int			ft_abs(int n);
void		free_stack(t_stack **stack);
void		exit_with_error(t_stack **stack_a, t_stack **stack_b);
t_stack		*init_stack(int argc, char **argv);
int			count_stack_size(t_stack *stack);
void		assign_sorted_indexes(t_stack *stack, int size);
int			is_stack_sorted(t_stack *stack);
void		do_swap(t_stack **stack_a, t_stack **stack_b, char *op);
void		sort_three(t_stack **stack);
void		do_rotate(t_stack **stack_a, t_stack **stack_b, char *op);
void		do_push(t_stack **stack_a, t_stack **stack_b, char *op);
void		big_sort(t_stack **stack_a, t_stack **stack_b);
void		find_targets_in_a(t_stack **stack_a, t_stack **stack_b);
void		calculate_costs(t_stack **stack_a, t_stack **stack_b);
void		execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);
int			find_min_index(t_stack *stack_a);
void		update_current_index(t_stack **stack);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
t_stack		*init_stack_from_args(char **args);
char		*ft_strdup(const char *s);

#endif
