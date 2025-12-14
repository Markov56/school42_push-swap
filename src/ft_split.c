/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:28:50 by rmarkov           #+#    #+#             */
/*   Updated: 2025/12/14 17:19:22 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

static int	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_extract_word(const char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	len = i;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	ft_free_result(char **arr, size_t count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**words;

	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = ft_extract_word(s + i, c);
			if (!words[j])
				return (ft_free_result(words, j), NULL);
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
