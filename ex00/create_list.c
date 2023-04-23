/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhong <auhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:37:43 by auhong            #+#    #+#             */
/*   Updated: 2023/04/23 22:39:28 by auhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*create_list(long key, char *value)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list->key = key;
	new_list->value = value;
	return (new_list);
}