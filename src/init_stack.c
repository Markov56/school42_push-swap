/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:59 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/10 18:30:01 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = value;
	node->current_index = -1;
	node->sorted_index = -1;
	node->target_index = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

static void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack		*stack;
	t_stack		*new_node;
	long int	num;
	int			i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit_with_error(&stack, NULL);
		new_node = create_node((int)num);
		if (!new_node)
			exit_with_error(&stack, NULL);
		add_back(&stack, new_node);
		i++;
	}
	return (stack);
}
