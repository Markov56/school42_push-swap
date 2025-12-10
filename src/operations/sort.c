#include "push_swap.h"

/* ============================================================================
 * ЧАСТИНА 1: Розрахунок оптимальних рухів
 * ============================================================================ */

/**
 * Знаходить позицію в стеку A, куди треба вставити елемент з B
 * Шукає найменший елемент в A, який більший за поточний елемент з B
 * Якщо такого немає — повертає позицію мінімального елемента
 */
static int	find_target_position_in_a(t_stack **stack_a, int b_index)
{
	t_stack	*a;
	int		target_index;
	int		target_pos;

	a = *stack_a;
	target_index = INT_MAX;
	target_pos = 0;
	
	// Шукаємо найменший елемент, який більший за b_index
	while (a)
	{
		if (a->sorted_index > b_index && a->sorted_index < target_index)
		{
			target_index = a->sorted_index;
			target_pos = a->current_index;
		}
		a = a->next;
	}
	
	// Якщо не знайшли (b_index найбільший) — шукаємо мінімум в A
	if (target_index == INT_MAX)
	{
		a = *stack_a;
		target_index = INT_MAX;
		while (a)
		{
			if (a->sorted_index < target_index)
			{
				target_index = a->sorted_index;
				target_pos = a->current_index;
			}
			a = a->next;
		}
	}
	
	return (target_pos);
}

/**
 * Оновлює позиції всіх елементів стеку (0, 1, 2, ...)
 */
void	update_positions(t_stack **stack)
{
	t_stack	*node;
	int		i;

	node = *stack;
	i = 0;
	while (node)
	{
		node->current_index = i;
		node = node->next;
		i++;
	}
}

/**
 * Для кожного елемента в B знаходить його цільову позицію в A
 */
void	find_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;

	update_positions(stack_a);
	update_positions(stack_b);
	
	b = *stack_b;
	while (b)
	{
		b->target_index = find_target_position_in_a(stack_a, b->sorted_index);
		b = b->next;
	}
}

/**
 * Розраховує кількість рухів для переміщення кожного елемента з B в A
 * Позитивне число = rotate (ra/rb)
 * Негативне число = reverse rotate (rra/rrb)
 */
void	calculate_move_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		size_a;
	int		size_b;

	b = *stack_b;
	size_a = count_stack_size(*stack_a);
	size_b = count_stack_size(*stack_b);
	
	while (b)
	{
		// Кількість рухів для стеку B
		b->cost_b = b->current_index;
		if (b->current_index > size_b / 2)
			b->cost_b = (size_b - b->current_index) * -1;  // Краще reverse
		
		// Кількість рухів для стеку A
		b->cost_a = b->target_index;
		if (b->target_index > size_a / 2)
			b->cost_a = (size_a - b->target_index) * -1;  // Краще reverse
		
		b = b->next;
	}
}

/* ============================================================================
 * ЧАСТИНА 2: Виконання оптимальних рухів
 * ============================================================================ */

/**
 * Одночасно обертає обидва стеки вниз (rrr) поки можливо
 */
static void	rotate_both_reverse(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		do_rotate(sa, sb, "rrr");
	}
}

/**
 * Одночасно обертає обidва стеки вгору (rr) поки можливо
 */
static void	rotate_both_up(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		do_rotate(sa, sb, "rr");
	}
}

/**
 * Обертає стек A до потрібної позиції
 */
static void	rotate_stack_a(t_stack **sa, int *moves)
{
	while (*moves != 0)
	{
		if (*moves > 0)
		{
			do_rotate(sa, NULL, "ra");
			(*moves)--;
		}
		else
		{
			do_rotate(sa, NULL, "rra");
			(*moves)++;
		}
	}
}

/**
 * Обертає стек B до потрібної позиції
 */
static void	rotate_stack_b(t_stack **sb, int *moves)
{
	while (*moves != 0)
	{
		if (*moves > 0)
		{
			do_rotate(NULL, sb, "rb");
			(*moves)--;
		}
		else
		{
			do_rotate(NULL, sb, "rrb");
			(*moves)++;
		}
	}
}

/**
 * Знаходить і виконує найдешевший переніс з B в A
 * "Дешевий" = мінімальна сума |mv_a| + |mv_b|
 */
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		cheapest_cost;
	int		cost_a;
	int		cost_b;

	b = *stack_b;
	cheapest_cost = INT_MAX;
	
	// Знаходимо елемент з найменшою "ціною"
	while (b)
	{
		if (absolute(b->cost_a) + absolute(b->cost_b) < cheapest_cost)
		{
			cheapest_cost = absolute(b->cost_a) + absolute(b->cost_b);
			cost_a = b->cost_a;
			cost_b = b->cost_b;
		}
		b = b->next;
	}
	
	// Оптимізуємо: якщо обидва в один бік — крутимо разом
	if (cost_a < 0 && cost_b < 0)
		rotate_both_reverse(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both_up(stack_a, stack_b, &cost_a, &cost_b);
	
	// Докручуємо стеки окремо
	rotate_stack_a(stack_a, &cost_a);
	rotate_stack_b(stack_b, &cost_b);
	
	// Переносимо елемент з B в A
	do_push(stack_a, stack_b, "pa");
}

/* ============================================================================
 * ЧАСТИНА 3: Головний алгоритм сортування
 * ============================================================================ */

/**
 * Знаходить позицію найменшого елемента в стеку
 */
int	find_min_position(t_stack **stack)
{
	t_stack	*node;
	int		min_index;
	int		min_pos;

	update_positions(stack);
	
	node = *stack;
	min_index = INT_MAX;
	min_pos = 0;
	
	while (node)
	{
		if (node->sorted_index < min_index)
		{
			min_index = node->sorted_index;
			min_pos = node->current_index;
		}
		node = node->next;
	}
	
	return (min_pos);
}

/**
 * Фінальне обертання: ставить найменший елемент на верх стеку A
 */
static void	final_rotation(t_stack **stack_a)
{
	int	size;
	int	min_pos;

	size = count_stack_size(*stack_a);
	min_pos = find_min_position(stack_a);
	
	// Вибираємо коротший шлях
	if (min_pos > size / 2)
	{
		// Ближче через reverse rotate
		while (min_pos < size)
		{
			do_rotate(stack_a, NULL, "rra");
			min_pos++;
		}
	}
	else
	{
		// Ближче через rotate
		while (min_pos > 0)
		{
			do_rotate(stack_a, NULL, "ra");
			min_pos--;
		}
	}
}

/**
 * Переносить половину елементів з A в B, залишаючи 3 у A
 * Переносить спочатку менші елементи (sorted_index <= size/2)
 */
static void	push_half_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	iterations;

	size = count_stack_size(*stack_a);
	pushed = 0;
	iterations = 0;
	
	// Переносимо менші елементи (перша половина)
	while (size > 6 && iterations < size && pushed < size / 2)
	{
		if ((*stack_a)->sorted_index <= size / 2)
		{
			do_push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			do_rotate(stack_a, NULL, "ra");
		iterations++;
	}
	
	// Переносимо решту, залишаючи 3 елементи
	while (size - pushed > 3)
	{
		do_push(stack_a, stack_b, "pb");
		pushed++;
	}
	
	// Сортуємо 3 елементи в A
	sort_three(stack_a);
}

/**
 * Алгоритм сортування для великих стеків (більше 3 елементів)
 * 
 * Стратегія:
 * 1. Перенести половину елементів у стек B (залишити 3 в A)
 * 2. Відсортувати 3 елементи в A
 * 3. По черзі повертати елементи з B в A у правильні місця
 * 4. Фінальне обертання — поставити мінімум на верх
 */
void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	// Крок 1-2: Перенести половину в B, відсортувати 3 в A
	push_half_to_b(stack_a, stack_b);
	
	// Крок 3: Повертаємо всі елементи з B в A
	while (*stack_b)
	{
		find_target_positions(stack_a, stack_b);
		calculate_move_cost(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	
	// Крок 4: Якщо не відсортовано — фінальне обертання
	if (!is_stack_sorted(*stack_a))
		final_rotation(stack_a);
}

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}