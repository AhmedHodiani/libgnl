/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:06:28 by ataher            #+#    #+#             */
/*   Updated: 2024/09/16 08:33:20 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup(const char *s1)
{
    size_t len = 0;
    while (s1[len])
        len++;

    char *dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return NULL;

    int i = -1;
    while(s1[++i])
        dup[i] = s1[i];

    dup[i] = '\0';
    return dup;
}

// Function to create a new buffer node
static t_buffer *create_buffer(const char *content)
{
    t_buffer *new_node = (t_buffer *)malloc(sizeof(t_buffer));
    if (!new_node) return NULL; // Check for memory allocation failure

    // Allocate and copy the content
    new_node->content = ft_strdup(content);
    if (!new_node->content) {
        free(new_node); // Free the node if content allocation fails
        return NULL;
    }

    // Initialize the next pointer
    new_node->next = NULL;

    return new_node;
}

void append_buffer(t_buffer **head, const char *content)
{
    if (content[0] == '\0') return; // Check for empty content

    t_buffer *new_node = create_buffer(content);
    if (!new_node) return; // Check for memory allocation failure

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
    } else {
        // Otherwise, traverse to the end of the list
        t_buffer *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


void print_buffers(const t_buffer *head)
{
    const t_buffer *current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

void free_buffers(t_buffer *head)
{
    t_buffer *current = head;
    t_buffer *next;

    while (current != NULL) {
        next = current->next; // Save the next node
        free(current->content); // Free the content
        free(current); // Free the node
        current = next; // Move to the next node
    }
}


