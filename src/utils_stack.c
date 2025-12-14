/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:47 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/14 18:53:19 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	exit_with_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	assign_sorted_indexes(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*min_node;
	int		index;

	index = 0;
	while (index < size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->sorted_index == -1 && (!min_node || current->num < min_node->num))
				min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->sorted_index = index;
		index++;
	}
}

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
