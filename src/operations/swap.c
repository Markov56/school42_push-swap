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

// static void	swap(t_stack *stack)
// {
// 	int	temp_num;
// 	int	temp_rank;

// 	if (!stack || !stack->next)
// 		return ;
// 	temp_num = stack->num;
// 	stack->num = stack->next->num;
// 	stack->next->num = temp_num;
// 	temp_rank = stack->sorted_index;
// 	stack->sorted_index = stack->next->sorted_index;
// 	stack->next->sorted_index = temp_rank;
// }

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