/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:40:12 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/06 11:19:41 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	*extract_word(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strncpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static void	*free_split_and_return_null(char **result)
{
	free_split(result);
	return (NULL);
}

static char	**fill_split(const char *s, char c, char **result, int word_count)
{
	int	i;

	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = extract_word(s, c);
			if (!result[i])
				return (free_split_and_return_null(result));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (fill_split(s, c, result, word_count));
}
