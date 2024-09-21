/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:28 by ataher            #+#    #+#             */
/*   Updated: 2024/09/21 10:32:11 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strdup_till_newline(const char *s1)
{
	size_t	len;
	char	*new_string;
	int		i;

	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	if (s1[len] == '\n')
		len++;
	new_string = malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		new_string[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
		new_string[i++] = '\n';
	new_string[i] = '\0';
	return (new_string);
}

static t_buffer	*create_buffer(const char *content)
{
	t_buffer	*new_node;

	new_node = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new_node)
		return (NULL);
	new_node->content = ft_strdup_till_newline(content);
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	append_buffer(t_buffer **head, const char *content)
{
	t_buffer	*new_node;
	t_buffer	*current;

	if (content[0] == '\0')
		return (1);
	new_node = create_buffer(content);
	if (!new_node)
		return (0);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (1);
}

void	free_buffers(t_buffer *head)
{
	t_buffer	*current;
	t_buffer	*next;

	if (head == NULL)
		return ;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}
