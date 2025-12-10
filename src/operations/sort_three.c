#include "push_swap.h"

static int	find_max_rank(t_stack *stack)
{
	int	max_rank;

	max_rank = stack->sorted_index;
	stack = stack->next;
	while (stack)
	{
		if (stack->sorted_index > max_rank)
			max_rank = stack->sorted_index;
		stack = stack->next;
	}
	return (max_rank);
}

void	sort_three(t_stack **stack)
{
	int	max_rank;

	if (is_stack_sorted(*stack))
		return ;
	max_rank = find_max_rank(*stack);
	if ((*stack)->sorted_index == max_rank)
		do_rotate(stack, NULL, "ra");
	else if ((*stack)->next->sorted_index == max_rank)
		do_rotate(stack, NULL, "rra");
	if ((*stack)->sorted_index > (*stack)->next->sorted_index)
		do_swap(stack, NULL, "sa");
}