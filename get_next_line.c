/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/14 17:29:16 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed: read, malloc, free
*/
# include "get_next_line.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t	i;

// 	if (src < dest)
// 	{
// 		i = n;
// 		while (i > 0)
// 		{
// 			i--;
// 			((char *)dest)[i] = ((char *)src)[i];
// 		}
// 	}
// 	else if (src > dest)
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			((char *)dest)[i] = ((char *)src)[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }
// size_t	ft_strlen_till_break(char const *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] && s[i] != '\n')
// 		i++;
// 	return (i);
// }

// size_t	ft_strlen(char const *s)
// {
// 	if (s == NULL)
// 		return (0);
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// static	char	*ft_strcpy_till_break(char *dest, const char *src)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] && src[i] != '\n')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strdup_till_break(const char *s)
// {
// 	char	*ptr;

// 	ptr = malloc(ft_strlen_till_break(s) + 1);
// 	if (ptr == NULL)
// 		return (NULL);
// 	return (ft_strcpy_till_break(ptr, s));
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*str;

// 	str = (char *)s;
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		str++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)str);
// 	return (NULL);
// }

// char	*concat_till_break(char *prefix_string, char *suffix_string)
// {
// 	char	*new_string;
// 	int		i;
// 	int		j;

// 	// if (prefix_string == NULL)
// 	// 	return (suffix_string);
// 	i = 0;
// 	new_string = malloc(sizeof(char) * (ft_strlen(prefix_string) + ft_strlen(suffix_string) + 1));
// 	if (new_string == NULL)
// 		return (NULL);
// 	while (prefix_string != NULL && prefix_string[i])
// 	{
// 		new_string[i] = prefix_string[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (suffix_string[j] && suffix_string[j] != '\n')
// 	{
// 		new_string[i + j] = suffix_string[j];
// 		j++;
// 	}
// 	new_string[i + j] = '\0';
// 	return (new_string);
// }

// char *skip_break(char *str)
// {
// 	char *ptr;

// 	ptr = ft_strchr(str, '\n');
// 	if (ptr != NULL)
// 		return (ptr + 1);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char 		temp_line[BUFFER_SIZE];
// 	int bytes_read = 0;
// 	int total_bytes_read = 0;
// 	// char	c;
// 	// int index;
// 	// printf("%s\n", temp_line);

// 	// printf("%s\n", temp_line);
// 	line = NULL;
// 	if (temp_line[0] != '\0')
// 	{
// 		printf("temp_line is NOTTTTTTTTTTTT EMPTY: %s\n", temp_line);

// 		// printf("%s\n", line);
// 		line = skip_break(temp_line);
// 		printf("line b4==>: %s\n", line);
// 	}
// 	// line = concat_till_break(line, "");

// 	while ((bytes_read = read(fd, temp_line, BUFFER_SIZE)) > 0)
// 	{
// 		printf("bytes_read: %d\t %s\n", bytes_read, temp_line);

// 		total_bytes_read += bytes_read;
// 		line = concat_till_break(line, temp_line);

// 		if (bytes_read != (int)ft_strlen_till_break(temp_line))
// 			break;
// 	}
// 	// printf("total: %d", total_bytes_read);
// 	printf("\n%s\n", line);
// 	printf("===================================\n");


// 	// line = ft_strdup_till_break(temp_line);
// 	// printf("%s\n", line);
// 	// index = 0;
// 	// while(read(fd, &c, 1) != 0 && c != '\n')
// 	// {
// 	// 	temp_line = malloc(sizeof(char) * index + 2);
// 	// 	ft_memmove(temp_line, line, index);

// 	// 	temp_line[index] = c;
// 	// 	temp_line[index + 1] = '\0';

// 	// 	// free(line);
// 	// 	line = ft_strdup(temp_line);

// 	// 	free(temp_line);
// 	// 	index++;
// 	// }

// 	return (line);
// }

long	ft_strchr(const char *s, char c)
{
	long	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	temp_line[BUFFER_SIZE];


	long line_len;
	long total_line_len;

	printf("index: %li\n", line_len);

	if (line_len == -1)
	{
		read(fd, temp_line, BUFFER_SIZE);
		line_len += ft_strchr(temp_line, '\n');
	}
	else {

		char *line = malloc(sizeof(char) * (line_len + 1));
	}


	// char **splitted;

	// read(fd, temp_line, BUFFER_SIZE);

	// splitted = ft_split(temp_line, '\n');

	// while (*splitted)
	// {
	// 	printf("%s\n", *splitted);
	// 	splitted++;
	// }

}


int main()
{
	int fd = open("out.txt", O_RDONLY);
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
}
