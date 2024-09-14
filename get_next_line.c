/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/14 11:05:09 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed: read, malloc, free
*/
# include "get_next_line.h"

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
size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	return (ft_strcpy(ptr, s));
}


char	*get_next_line(int fd)
{
	char		*line;
	char 		*temp_line;
	char	c;
	int index;

	index = 0;
	while(read(fd, &c, 1) != 0 && c != '\n')
	{
		temp_line = malloc(sizeof(char) * index + 2);
		ft_memmove(temp_line, line, index);

		temp_line[index] = c;
		temp_line[index + 1] = '\0';

		// free(line);
		line = ft_strdup(temp_line);

		free(temp_line);
		index++;
	}

	return (line);
}

int main()
{
	int fd = open("out.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
