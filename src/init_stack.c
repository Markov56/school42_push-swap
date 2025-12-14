/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:29:59 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/14 16:49:43 by rmarkov          ###   ########.fr       */
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

void free_split(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
		 free(arr[i++]);
	free(arr);
}


t_stack *init_stack_from_args(char **args)
{
	t_stack *stack;
	int		i;

	stack = NULL;
	i = 0;
	while (args[i])
	{
		add_back(&stack, create_node(ft_atoi(args[i])));
		i++;
	}
	return (stack);
}
