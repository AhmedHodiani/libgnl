/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:26 by ataher            #+#    #+#             */
/*   Updated: 2025/01/14 19:05:50 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
ssize_t	ft_strchr_index(const char *s, char c);

typedef struct s_buffer
{
	char			*content;
	struct s_buffer	*next;
}	t_buffer;

int		append_buffer(t_buffer **head, const char *content);
void	print_buffers(const t_buffer *head);
void	free_buffers(t_buffer *head);

#endif
