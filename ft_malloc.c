/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:23 by hmeftah           #+#    #+#             */
/*   Updated: 2023/05/26 14:48:21 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*allocate_memory(unsigned int size, t_address **addresses)
{
	void		*ptr;
	t_address	*node;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	node = create_node(ptr, size);
	if (node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	add_node_back(addresses, node);
	return (ptr);
}

static void	*free_memory(t_address **addresses)
{
	t_address	*t_node;

	t_node = *addresses;
	if (!*addresses)
		return (NULL);
	while (t_node->next)
	{
		t_node = t_node->next;
		destroy_node(t_node->prev);
	}
	destroy_node(t_node);
	*addresses = NULL;
	return (NULL);
}

static void	*free_pointer(void *ptr, t_address *addresses)
{
	t_address	*temp;

	temp = addresses;
	while (temp)
	{
		if (temp->ptr == ptr)
		{
			temp->prev->next = temp->next;
			free(temp->ptr);
			temp->dealloc = 1;
			temp->size = 0;
			temp->ptr = NULL;
			free(temp);
			return (NULL);
		}
		temp = temp->next;
	}
	return (NULL);
}

static void	*get_t_size(t_address *addresses, unsigned int *t_size)
{
	t_address	*temp;
	uint32_t	size_max;
	uint32_t	size_ptr;

	size_max = 0;
	size_ptr = 0;
	temp = addresses;
	if (!addresses)
		return (NULL);
	while (temp)
	{
		size_ptr += temp->size;
		size_max += size_ptr + sizeof(t_address);
		temp = temp->next;
	}
	if (t_size)
		*t_size = size_ptr;
	return (NULL);
}

/*
- Allocates Memory using malloc(), Returns a pointer on success.
- Has three types ALLOC, FREE, FREE_ALL, T_SIZE.
- ALLOC to allocate memory for a pointer.
- FREE to free a pointer.
- FREE_ALL to free all pointers allocated since the beginning of the program.
- T_SIZE prints the total size of the allocated memory.
*/
void	*ft_malloc(unsigned int size, void	*free_ptr,
	int type, uint32_t *t_size)
{
	static t_address	*addresses = NULL;

	if (type == ALLOC)
		return (allocate_memory(size, &addresses));
	else if (type == FREE)
		return (free_pointer(free_ptr, addresses));
	else if (type == FREE_ALL)
		return (free_memory(&addresses));
	else if (type == T_SIZE)
		return (get_t_size(addresses, t_size));
	return (NULL);
}
