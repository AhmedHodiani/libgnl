/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/16 14:21:33 by ataher           ###   ########.fr       */
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

	size_t line_index = 0;
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
	static size_t	start_index;

	t_buffer 		*buffer_list;
	size_t			newline_index;
	size_t			line_len;
	ssize_t			read_output;


	if (!temp_line[0])
	{
		read_output = read(fd, temp_line, BUFFER_SIZE);
		if (read_output <= 0)
			return NULL;
		start_index = 0;
	}
	else
		start_index += ft_strchr(temp_line + start_index, '\n') + 1;

	// printf("start_index: %lu\n", start_index);
	// printf("temp: %s%%\n", temp_line + start_index);
	// if (temp_line[start_index] == '\n')
	// {
	// 	return NULL;
	// }

	line_len = 0;
	buffer_list = NULL;
	while (1)
	{
		append_buffer(&buffer_list, temp_line + start_index);
		newline_index = ft_strchr(temp_line + start_index, '\n');
		line_len += newline_index;

		if (newline_index != BUFFER_SIZE)
			break;

		read_output = read(fd, temp_line, BUFFER_SIZE);
		start_index = 0;

		if (read_output <= 0)
			return NULL;
	}
	// print_buffers(buffer_list);
	// printf("##line_len: %lu\n", line_len);
	return (ft_concat_buffers(buffer_list, line_len));
	// return "asdf";
}


// int main()
// {
// 	int fd = open("out.txt", O_RDONLY);

// 	get_next_line(fd); // "12315345\n"
// 	get_next_line(fd); // "134513451345345\n"

// 	char mystring[10];

// 	read(fd, mystring, 1); // "1"
// 	read(fd, mystring, 1); // "2"

// 	printf("##line: %s%%\n\n", get_next_line(fd));
// 	printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("---\n");
// 	printf("##line: %s%%\n\n", get_next_line(fd));
// 	printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));
// 	// printf("##line: %s%%\n", get_next_line(fd));

// 	// char readed[100];

// 	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
// 	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
// 	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
// 	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
// 	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);


// 	// printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("##line: %s%%\n\n", get_next_line(fd));
// 	// printf("##line: %s%%\n\n", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// }
