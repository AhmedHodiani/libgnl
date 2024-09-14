/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/14 09:14:19 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed: read, malloc, free
*/
# include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;

	return (line);
}

int main()
{
	int fd = open("out", O_RDONLY);
	char *line = get_next_line(fd);

	printf("\n\n%s\n\n", line);
}
