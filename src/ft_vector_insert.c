/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   CODAM C FILE                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by wmaguire      #+#    #+#                 */
/*   Updated: 1970/01/01 00:00:00 by wmaguire     ########   codam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3
Copyright (C) 2022  Will Maguire

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#include <stdlib.h>
#include "libft.h"

t_vector	*vector_new(void *data)
{
	t_vector	*new;

	new = ft_calloc(sizeof(t_vector), 1);
	if (!new)
		return (NULL);
	new->index = -1;
	new->next = NULL;
	new->previous = NULL;
	new->data = data;
	return (new);
}

int	vector_remove(t_vector *head, int idx, void (*dealloc)(void *))
{
	t_vector *element;
	t_vector *element_next;

	if (head == NULL || idx > vector_size(head) || idx < 0)
		return (FALSE);
	element = NULL;
	element = vec_get_element(head, idx);
	if (!element)
		return (FALSE);
	element_next = element->next;
	element->previous->next = element_next;
	element_next->previous = element->previous;
	if (dealloc)
		dealloc(element->data);
	free(element);
	update_indices(element_next, 0);
	return (TRUE);
}

int	vector_insert(t_vector *head, int idx, void *content)
{
	t_vector	*new;
	t_vector	*element;

	if (head == NULL || idx > vector_size(head) || idx < 0)
		return (FALSE);
	element = NULL;
	new = vector_new(content);
	if (!new)
		return (FALSE);
	element = vec_get_element(head, idx);
	if (!element)
	{
		free(new);
		return (FALSE);
	}
	new->next = element;
	new->previous = element->previous;
	element->previous = new;
	new->index = element->index;
	update_indices(element, 1);
	return (TRUE);
}
