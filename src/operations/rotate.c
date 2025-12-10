/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:26:53 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:26:54 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL; 
}

static void	reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(op, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	ft_putstr(op);
}
