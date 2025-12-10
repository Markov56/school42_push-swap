/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:16 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:29:18 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		size_a;
	int		size_b;

	current = *stack_b;
	size_a = count_stack_size(*stack_a);
	size_b = count_stack_size(*stack_b);
	while (current)
	{
		if (current->current_index > size_b / 2)
			current->cost_b = (size_b - current->current_index) * -1;
		else
			current->cost_b = current->current_index;
		if (current->target_index > size_a / 2)
			current->cost_a = (size_a - current->target_index) * -1;
		else
			current->cost_a = current->target_index;
		current = current->next;
	}
}
