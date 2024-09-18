/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/18 13:18:56 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
	// return (BUFFER_SIZE);
	return (-1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

size_t	len_buffers(t_buffer *buffer_list)
{
	size_t line_len = 0;
    while (buffer_list != NULL)
	{
		int i = -1;
		while (buffer_list->content[++i]);
		line_len += i;

		buffer_list = buffer_list->next;
    }
	return (line_len);
}

char	*ft_concat_buffers(t_buffer *buffer_list)
{
	char		*line;
	t_buffer	*temp = buffer_list;
	size_t		line_index;

	line = malloc(sizeof(char) * (len_buffers(buffer_list) + 1));
	if (!line)
		return (NULL);

	line_index = 0;
    while (temp != NULL) {
		int i = 0;
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


char	*get_next_line(int fd)
{
	static char		temp_line[BUFFER_SIZE];
	t_buffer 		*buffer_list;

	if (!temp_line[0])
	{
		if (read(fd, temp_line, BUFFER_SIZE) <= 0)
			return NULL;
	}
	else
		ft_memmove(temp_line, temp_line + ft_strchr(temp_line, '\n') + 1, BUFFER_SIZE);

	buffer_list = NULL;
	while (1)
	{
		append_buffer(&buffer_list, temp_line);
		if (ft_strchr(temp_line, '\n') != -1) // newline found
			break;
		if (read(fd, temp_line, BUFFER_SIZE) <= 0)
			return NULL;
	}
	return (ft_concat_buffers(buffer_list));
}


int main()
{
	int fd = open("out.txt", O_RDONLY);

	// static char temp[BUFFER_SIZE];


	// read(fd, temp, BUFFER_SIZE);
	// printf("temp: %s%%\n", temp);


	// read(fd, temp, BUFFER_SIZE);
	// printf("temp: %s%%\n", temp);

	// get_next_line(fd);
	// get_next_line(fd);


	// read(fd, temp, 2);
	// printf("temp: %s%%\n", temp);

	// read(fd, temp, 2);
	// printf("temp: %s%%\n", temp);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);

	// char mystring[10];

	// read(fd, mystring, 1); // "1"
	// read(fd, mystring, 1); // "2"

	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	printf("%s%%\n", get_next_line(fd));
	// 	printf("------------------------------------\n\n");

	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("------------------------------------\n\n");

	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("---\n");
	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));
	// printf("##line: %s%%\n", get_next_line(fd));

	// char readed[100];

	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);
	// printf("%ld -> %s%%\n\n\n", read(fd, readed, 10), readed);


	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n\n", get_next_line(fd));
	// printf("##line: %s%%\n\n", get_next_line(fd));
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
