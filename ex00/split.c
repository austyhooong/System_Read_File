/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhong <auhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:31:14 by qiwang            #+#    #+#             */
/*   Updated: 2023/04/23 23:36:34 by auhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == 32))
	{
		i++;
	}
	while ((*(str + i) == '+') || (*(str + i) == '-'))
	{
		if (*(str + i) == '-')
			sign = sign * (-1);
		i++;
	}
	result = 0;
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		result = result * 10;
		result = result + *(str + i) - '0';
		i++;
	}
	result = result * sign;
	return (result);
}

int	find_size(long number, int dictionary_values[32])
{
	int	size;
	int	idx;

	size = 0;
	idx = 0;
	while (number)
	{
		while (idx < 32 && number < dictionary_values[idx])
		{
			++idx;
		}
		if (idx >= 32)
			break ;
		++size;
		if (number >= 100)
			++size;
		number %= dictionary_values[idx];
	}
	return (size);
}

void	create_digit(int *digits, int *idx)
{
	digits[(*idx)++] = 1000000000;
	digits[(*idx)++] = 1000000;
	digits[(*idx)++] = 1000;
	digits[(*idx)++] = 100;
	digits[(*idx)++] = 90;
	digits[(*idx)++] = 80;
	digits[(*idx)++] = 70;
	digits[(*idx)++] = 60;
	digits[(*idx)++] = 50;
	digits[(*idx)++] = 40;
	digits[(*idx)++] = 30;
	digits[(*idx)++] = 20;
	digits[(*idx)++] = 19;
	digits[(*idx)++] = 18;
	digits[(*idx)++] = 17;
	digits[(*idx)++] = 16;
}

void	create_digit2(int *digits, int *idx)
{
	digits[(*idx)++] = 15;
	digits[(*idx)++] = 14;
	digits[(*idx)++] = 13;
	digits[(*idx)++] = 12;
	digits[(*idx)++] = 11;
	digits[(*idx)++] = 10;
	digits[(*idx)++] = 9;
	digits[(*idx)++] = 8;
	digits[(*idx)++] = 7;
	digits[(*idx)++] = 6;
	digits[(*idx)++] = 5;
	digits[(*idx)++] = 4;
	digits[(*idx)++] = 3;
	digits[(*idx)++] = 2;
	digits[(*idx)++] = 1;
	digits[(*idx)++] = 0;
}

int	*parse_number(char *output, int *size)
{
	int	dictionary_values[32];
	int	number;
	int	i;
	int	inner_idx;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * (*size));
	number = ft_atoi(output);
	*size = find_size(number, dictionary_values);
	inner_idx = 0;
	create_digit(dictionary_values, &i);
	create_digit2(dictionary_values, &i);
	i = 0;
	while (i < 32 && number > 0)
	{
		while (i < 32 && number < dictionary_values[i])
			++i;
		if (i == 32)
			break ;
		if (number < 100 && number / dictionary_values[i] != 1)
			continue ;
		if (number < 100)
			res[inner_idx++] = dictionary_values[i];
		if (number >= 100)
		{
			res[inner_idx++] = number / dictionary_values[i];
			if (number / dictionary_values[i] > 1)
				res[inner_idx++] = dictionary_values[i];
		}
		number = number % dictionary_values[i];
	}
	return (res);
}
