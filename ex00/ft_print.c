/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhong <auhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:15:50 by auhong            #+#    #+#             */
/*   Updated: 2023/04/23 22:06:02 by auhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	print_number(int number)
{
	if (number < 0)
	{
		ft_putchar('-');
		return (print_number(-number));
	}
	if (number / 10 == 0)
		ft_putchar(number + '0');
	else
	{
		print_number(number / 10);
		ft_putchar(number % 10 + '0');
	}
}

void	ft_putchar(char letter)
{
	write(1, &letter, 1);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar(str[idx]);
		++idx;
	}
}

int	find_key_size(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		++idx;
	return (idx);
}

int	print_dict(t_list *dict, int input[], int size)
{
	int		idx;
	t_list	*cur_word;

	idx = 0;
	while (idx < size)
	{
		cur_word = dict;
		while (cur_word)
		{
			if (cur_word->key == input[idx])
			{
				put_str(cur_word->value);
				break ;
			}
			cur_word = cur_word->next;
		}
		if (!cur_word)
		{
			put_str("Dict Error\n");
			return (0);
		}
	}
}
