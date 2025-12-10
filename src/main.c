#include "push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	t_stack	*tmp;

// 	tmp = stack;
// 	while (tmp)
// 	{
// 		printf("num: %d, sorted: %d, current: %d, target: %d, cost_a: %d, cost_b: %d\n",
// 			 tmp->num, tmp->sorted_index, tmp->current_index, tmp->target_index, tmp->cost_a, tmp->cost_b);
// 		tmp = tmp->next;
// 	}
// }

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_stack_sorted(*stack_a))
		do_swap(stack_a, NULL, "sa");
	if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && !is_stack_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!validate_input(argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	size = count_stack_size(stack_a);
	assign_sorted_indexes(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	// print_stack(stack_a);
	// print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
} 
