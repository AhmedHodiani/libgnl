/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:28 by ataher            #+#    #+#             */
/*   Updated: 2024/09/14 17:00:57 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static	int	ft_wordcount(char const *s, char delimiter)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (s[i + 1] == delimiter || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static	int	ft_strlen_till_delimiter(char const *s, char delimiter)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	return (i);
}

void	free_result(char **result, int wordcount)
{
	int	i;

	i = 0;
	while (i <= wordcount)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
}

char	**set_strings(char **result, int wordcount, char const *s, char c)
{
	int		wordlen;
	int		word;

	word = 0;
	while (word < wordcount)
	{
		while (*s == c)
			s++;
		wordlen = ft_strlen_till_delimiter(s, c);
		result[word] = malloc(sizeof(char) * (wordlen + 1));
		if (!result[word])
		{
			free_result(result, word);
			return (NULL);
		}
		ft_strlcpy(result[word], s, wordlen + 1);
		s += wordlen;
		word++;
	}
	result[word] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**result;

	wordcount = ft_wordcount(s, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (NULL);
	return (set_strings(result, wordcount, s, c));
}
