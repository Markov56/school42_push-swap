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

void	assign_sorted_indexes(t_stack *stack, int size)
{
	t_stack	*current;
	int		min_value;
	t_stack	*min_node;
	int		index;

	index = 0;
	while (index < size)
	{
		current = stack;
		min_value = INT_MAX;
		min_node = NULL;
		while (current)
		{
			if (current->sorted_index == -1 && current->num < min_value)
			{
				min_value = current->num;
				min_node = current;
			}
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