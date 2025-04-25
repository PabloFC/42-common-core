/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:23:52 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/25 13:11:31 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strncpy(char *dst, const char *src, int n) {
    while (n-- && *src)
        *dst++ = *src++;
    *dst = '\0';
}

bool is_sorted(t_stack_node *stack)
{
    if (!stack)
        return (true);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

void print_stack(t_stack_node *stack) // Solo para debug
{
    while (stack)
    {
        ft_printf("%d (idx: %d)\n", stack->value, stack->index);
        stack = stack->next;
    }
    ft_printf("----\n");
}

static int	count_words(const char *s, char c) {
    int count = 0;
    int in_word = 0;

    while (*s) {
        if (*s != c && !in_word) {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char	*extract_word(const char *s, char c) {
    int		len = 0;
    char	*word;

    while (s[len] && s[len] != c)
        len++;
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    ft_strncpy(word, s, len);  
    word[len] = '\0';
    return (word);
}

void	free_split(char **split) {
    int	i = 0;

    if (!split) return;
    while (split[i]) {
        free(split[i]);
        i++;
    }
    free(split);
}

char	**ft_split(const char *s, char c) {
    char	**result;
    int		word_count;
    int		i = 0;

    if (!s) return (NULL);
    word_count = count_words(s, c);
    result = malloc(sizeof(char *) * (word_count + 1));
    if (!result) return (NULL);
    while (*s && i < word_count) {
        while (*s == c) s++;
        if (*s) {
            result[i] = extract_word(s, c);
            if (!result[i]) return (free_split(result), NULL);
            i++;
            while (*s && *s != c) s++;
        }
    }
    result[i] = NULL;
    return (result);
}

