/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets_in_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:37 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:29:38 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_current_index(t_stack **stack)
{
	t_stack	*node;
	int		i;

	node = *stack;
	i = 0;
	while (node)
	{
		node->current_index = i;
		node = node->next;
		i++;
	}
}

static int	find_closest_bigger(t_stack *stack_a, int elem_index)
{
	int	closest;
	int	target;

	closest = INT_MAX;
	target = -1;
	while (stack_a)
	{
		if (stack_a->sorted_index > elem_index
			&& stack_a->sorted_index < closest)
		{
			closest = stack_a->sorted_index;
			target = stack_a->current_index;
		}
		stack_a = stack_a->next;
	}
	return (target);
}

int	find_min_index(t_stack *stack_a)
{
	int	min_sorted;
	int	min_pos;

	min_sorted = INT_MAX;
	min_pos = 0;
	while (stack_a)
	{
		if (stack_a->sorted_index < min_sorted)
		{
			min_sorted = stack_a->sorted_index;
			min_pos = stack_a->current_index;
		}
		stack_a = stack_a->next;
	}
	return (min_pos);
}

static int	find_target_in_a(t_stack **stack_a, int elem_index)
{
	int	target;

	target = find_closest_bigger(*stack_a, elem_index);
	if (target != -1)
		return (target);
	return (find_min_index(*stack_a));
}

void	find_targets_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_node;

	update_current_index(stack_a);
	update_current_index(stack_b);
	b_node = *stack_b;
	while (b_node)
	{
		b_node->target_index = find_target_in_a(stack_a, b_node->sorted_index);
		b_node = b_node->next;
	}
}
