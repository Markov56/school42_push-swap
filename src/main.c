/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:43:11 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/14 19:23:23 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("num: %d, sorted: %d, current: %d, target: %d, cost_a: %d, cost_b: %d\n", 
			tmp->num, tmp->sorted_index, tmp->current_index, tmp->target_index, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_stack_sorted(*stack_a))
		do_swap(stack_a, NULL, "sa");
	if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && !is_stack_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}

void	free_args(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char **prepare_args(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
		return (ft_split(argv[1], ' '));

	args = malloc(sizeof(char *) * argc);
	if (!args)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		args[i - 1] = ft_strdup(argv[i]);
		if (!args[i - 1])
			return (NULL);
		i++;
	}
	args[i - 1] = NULL;
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	char	**args;

	if (argc < 2)
		return (0);
	args = prepare_args(argc, argv);
	if (!args || !validate_input(args))
	{
		write(2, "Error\n", 6);
		free_split(args);
		return (1);
	}
	stack_a = init_stack_from_args(args);
	stack_b = NULL;
	size = count_stack_size(stack_a);
	assign_sorted_indexes(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_split(args);
	return (0);
} 
