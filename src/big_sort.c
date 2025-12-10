/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:06 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:29:07 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	keep_three_in_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed_count;
	int	i;

	pushed_count = 0;
	i = 0;
	size = count_stack_size(*stack_a);
	while (size > 6 && i < size && pushed_count < size / 2)
	{
		if ((*stack_a)->sorted_index < size / 2)
		{
			do_push(stack_a, stack_b, "pb");
			pushed_count++;
		}
		else
			do_rotate(stack_a, NULL, "ra");
		i++;
	}
	while (size - pushed_count > 3)
	{
		do_push(stack_a, stack_b, "pb");
		pushed_count++;
	}
	sort_three(stack_a);
}

static void	final_rotations(t_stack **stack_a)
{
	int	size;
	int	min_pos;
	int	moves;

	size = count_stack_size(*stack_a);
	update_current_index(stack_a);
	min_pos = find_min_index(*stack_a);
	if (min_pos > size / 2)
	{
		moves = size - min_pos;
		while (moves)
		{
			do_rotate(stack_a, NULL, "rra");
			moves--;
		}
	}
	else
	{
		moves = min_pos;
		while (moves)
		{
			do_rotate(stack_a, NULL, "ra");
			moves--;
		}
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	keep_three_in_a(stack_a, stack_b);
	while (*stack_b)
	{
		find_targets_in_a(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		final_rotations(stack_a);
}
