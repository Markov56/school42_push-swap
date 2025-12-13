/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cheapest_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:27 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:29:29 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rotate(stack_a, stack_b, "rr");
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	rotate_both_rev(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rotate(stack_a, stack_b, "rrr");
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	finish_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_rotate(stack_a, NULL, "ra");
			(*cost_a)--;
		}
		else
		{
			do_rotate(stack_a, NULL, "rra");
			(*cost_a)++;
		}
	}
}

static void	finish_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rotate(NULL, stack_b, "rb");
			(*cost_b)--;
		}
		else
		{
			do_rotate(NULL, stack_b, "rrb");
			(*cost_b)++;
		}
	}
}

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		min_cost;
	int		cost_a;
	int		cost_b;

	current = *stack_b;
	min_cost = INT_MAX;
	while (current)
	{
		if (ft_abs(current->cost_a) + ft_abs(current->cost_b) < min_cost)
		{
			min_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
			cost_a = current->cost_a;
			cost_b = current->cost_b;
		}
		current = current->next;
	}
	if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		rotate_both_rev(stack_a, stack_b, &cost_a, &cost_b);
	finish_rotate_a(stack_a, &cost_a);
	finish_rotate_b(stack_b, &cost_b);
	do_push(stack_a, stack_b, "pa");
}
