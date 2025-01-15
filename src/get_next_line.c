/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2025/01/14 19:06:46 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libgnl.h"

size_t	len_buffers(t_buffer *buffer_list)
{
	size_t	line_len;
	int		i;

	line_len = 0;
	while (buffer_list)
	{
		i = 0;
		while (buffer_list->content[i])
			i++;
		line_len += i;
		buffer_list = buffer_list->next;
	}
	return (line_len);
}

char	*ft_concat_buffers(t_buffer *buffer_list)
{
	char		*line;
	t_buffer	*temp;
	size_t		line_index;
	int			i;

	temp = buffer_list;
	line = malloc(sizeof(char) * (len_buffers(buffer_list) + 1));
	if (!line)
		return (NULL);
	line_index = 0;
	while (temp != NULL)
	{
		i = 0;
		while (temp->content[i])
		{
			line[line_index + i] = temp->content[i];
			i++;
		}
		line_index += i;
		temp = temp->next;
	}
	line[line_index] = '\0';
	free_buffers(buffer_list);
	return (line);
}

char	*read_buffer(int fd, ssize_t *read_bytes,
	char *temp_line, t_buffer *buffer_list)
{
	*read_bytes = read(fd, temp_line, BUFFER_SIZE);
	if (*read_bytes < 0 || (*read_bytes == 0 && temp_line[0] == '\0'))
	{
		free_buffers(buffer_list);
		temp_line[0] = '\0';
		return (NULL);
	}
	return ("");
}

int	init(int fd, char *temp_line, t_buffer *buffer_list, ssize_t *read_bytes)
{
	ssize_t	newline_index;
	int		i;

	*read_bytes = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		temp_line[0] = '\0';
		return (0);
	}
	if (temp_line[0] == '\0')
	{
		if (!read_buffer(fd, read_bytes, temp_line, buffer_list))
			return (0);
	}
	else
	{
		newline_index = ft_strchr_index(temp_line, '\n');
		if (newline_index == -1)
			return (0);
		i = -1;
		while (temp_line[++i + newline_index + 1])
			temp_line[i] = temp_line[i + newline_index + 1];
		temp_line[i] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		temp_line[BUFFER_SIZE];
	ssize_t			read_bytes;
	t_buffer		*buffer_list;

	buffer_list = NULL;
	if (init(fd, temp_line, buffer_list, &read_bytes) == 0)
		return (NULL);
	while (1)
	{
		temp_line[read_bytes] = '\0';
		if (!append_buffer(&buffer_list, temp_line))
		{
			free_buffers(buffer_list);
			temp_line[0] = '\0';
			return (NULL);
		}
		if (ft_strchr_index(temp_line, '\n') != -1 || read_bytes < BUFFER_SIZE)
			break ;
		else if (!read_buffer(fd, &read_bytes, temp_line, buffer_list))
			return (NULL);
		else if (read_bytes == 0 && temp_line[0] != '\0')
			break ;
	}
	return (ft_concat_buffers(buffer_list));
}
