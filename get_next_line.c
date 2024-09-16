/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/16 08:34:17 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (BUFFER_SIZE);
}


char	*ft_concat_buffers(t_buffer *buffer_list, size_t line_len)
{
	char		*line;
	t_buffer *temp = buffer_list;

	line = malloc(sizeof(char) * (line_len + 1));

	int line_index = 0;
    while (temp != NULL) {
		int i = 0;
		while (temp->content[i] && (line_index + i) < line_len)
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


char	*get_next_line(int fd)
{
	static char		temp_line[BUFFER_SIZE];
	t_buffer 		*buffer_list;
	size_t			line_len;
	size_t			newline_index;
	int				read_output;

	line_len = 0;
	buffer_list = NULL;
	if (temp_line[0]) // if temp_line is not empty
	{
		newline_index = ft_strchr(temp_line, '\n');
		printf("add to buffer: %s%%\n", temp_line + newline_index + 1);
		append_buffer(&buffer_list, (temp_line + newline_index + 1));
		line_len = BUFFER_SIZE - (newline_index + 1);
	}
	while (1)
	{
		if ((read_output = read(fd, temp_line, BUFFER_SIZE)) < 0)
			return NULL;
		// printf("read_output: %d%% --> temp: %s%%\n", read_output, temp_line);
		// if (read_output == 0)
		// {
			// printf("buffers:\n");
			// print_buffers(buffer_list);
		// 	break;
		// }
		append_buffer(&buffer_list, temp_line);
		newline_index = ft_strchr(temp_line, '\n');
		line_len += newline_index;
		if (newline_index != BUFFER_SIZE)
			break;
	}
	print_buffers(buffer_list);
	return (ft_concat_buffers(buffer_list, line_len));
}


int main()
{
	int fd = open("out.txt", O_RDONLY);
	printf("line: %s%%\n", get_next_line(fd));
	printf("---\n");
	printf("line: %s%%\n", get_next_line(fd));
	printf("---\n");
	printf("line: %s%%\n", get_next_line(fd));
	printf("---\n");
	printf("line: %s%%\n", get_next_line(fd));
	printf("---\n");
	printf("line: %s%%\n", get_next_line(fd));
	printf("---\n");
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
}
