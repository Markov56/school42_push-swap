/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:26:35 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:26:38 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src_stack, t_stack **dst_stack)
{
	t_stack	*temp;

	temp = (*src_stack)->next;
	(*src_stack)->next = *dst_stack;
	*dst_stack = *src_stack;
	*src_stack = temp;
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(op, "pb") == 0)
		push(stack_a, stack_b);
	ft_putstr(op);
}
