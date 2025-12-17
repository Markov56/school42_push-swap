/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:30:08 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/16 20:49:34 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

static int	is_int_range(char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		n = n * 10 + (*str - '0');
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && - n < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

static void	normalize_number(char *str)
{
	int	src_ind;
	int	dst_ind;

	src_ind = 0;
	dst_ind = 0;
	if (str[src_ind] == '+' || str[src_ind] == '-')
		src_ind++;
	while (str[src_ind] == '0')
		src_ind++;
	if (!str[src_ind])
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if (str[0] == '-')
		str[dst_ind++] = '-';
	while (str[src_ind])
		str[dst_ind++] = str[src_ind++];
	str[dst_ind] = '\0';
}

static int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_num(args[i]))
			return (0);
		normalize_number(args[i]);
		if (!is_int_range(args[i]))
			return (0);
		i++;
	}
	if (has_duplicates(args))
		return (0);
	return (1);
}
