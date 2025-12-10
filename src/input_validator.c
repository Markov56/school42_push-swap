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

static char	*normalize_number(char *str)
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
		return (str);
	}
	if (str[0] == '-')
		str[dst_ind++] = '-';
	while (str[src_ind])
		str[dst_ind++] = str[src_ind++];
	str[dst_ind] = '\0';
	return (str);
}

static int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = 1;
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

	i = 1;
	while (args[i])
	{
		if (!is_num(args[i]))
			return (0);
		args[i] = normalize_number(args[i]);
		i++;
	}
	if (has_duplicates(args))
		return (0);
	return (1);
}