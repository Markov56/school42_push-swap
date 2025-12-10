/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:28:19 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:28:21 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	do_swap(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	ft_putstr(op);
}
