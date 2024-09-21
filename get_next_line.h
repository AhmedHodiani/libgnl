/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:26 by ataher            #+#    #+#             */
/*   Updated: 2024/09/21 10:25:09 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
ssize_t	ft_strchr(const char *s, char c);

typedef struct s_buffer
{
	char			*content;
	struct s_buffer	*next;
}	t_buffer;

int		append_buffer(t_buffer **head, const char *content);
void	print_buffers(const t_buffer *head);
void	free_buffers(t_buffer *head);

#endif
