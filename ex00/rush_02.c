/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhong <auhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:25:18 by auhong            #+#    #+#             */
/*   Updated: 2023/04/23 23:43:25 by auhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include <stdlib.h>

void	print_number(int number);
void	ft_putchar(char letter);
void	ft_putstr(char *str);
int		*parse_number(char	*input, int *size); //wang san
char	*rm_spc(char *str);
int		find_key_size(char *str);
int		print_dict(t_list *dict, int input[], int size);
t_list	*create_list(long key, char *value);
int		*parse_number(char *input, int *size);
int	ft_atoi(char *str);

char	*expand(char *output, int size)
{
	char	*new_output;
	int		idx;

	idx = 0;
	new_output = malloc(size + 1);
	while (idx < size)
	{
		new_output[idx] = output[idx];
		++idx;
	}
	new_output[idx] = 0;
	free(output);
	return (new_output);
}

void	parse_key(long *key, char *value, char *output)
{
	int		idx;
	char	*start_output;
	int		key_size;
	int		key_idx;

	idx = 0;
	start_output = output;
	output = rm_spc(output);
	while (output[idx] != ':')
		++idx;

	*key = ft_atoi(start_output, idx);
	key_size = find_key_size(output + idx);
	value = malloc(key_size);
	key_idx = 0;
	while (output[idx] != '\0')
		value[key_idx++] = output[idx++];
	free(output);
}

t_list	*parse_dict(t_list *dict, int input[], char *output, int size)
{
	long	key;
	char	*value;
	int		idx;
	t_list	*new_dict;

	parse_key(&key, value, output);
	idx = 0;
	value = 0;
	new_dict = 0;
	while (idx < size)
	{
		if (key == input[idx])
		{
			if (!dict)
				dict = create_list(key, value);
			else
			{
				new_dict = create_list(key, value);
				new_dict->next = dict;
				dict = new_dict;
			}
			return (dict);
		}
	}
	return (dict);
}

t_list	*read_file(char *dict_path, t_list *dict, int input[], int input_size)
{
	char	buf[1];
	int		file_id;
	char	*output;
	int		size;

	file_id = open(dict_path, O_RDONLY);
	if (file_id == -1)
		ft_putstr("Dict Error\n");
	size = 0;
	while (read(file_id, buf, 1) != 0)
	{
		if (buf[0] == '\n')
		{
			dict = parse_dict(dict, input, output, input_size);
			free(output);
			size = 0;
		}
		else
			output = expand(output, ++size);
	}
	return (dict);
}

int	main(int argc, char *argv[])
{
	int		*input;
	int		size;
	t_list	*dict;
	int		idx;
	t_list	*cur_word;

	idx = 0;
	dict = 0;
	cur_word = 0;
	if (argc == 2)
	{
		print_number(atoi(argv[1]));
	}
	else if (argc == 3)
	{
		input = parse_number(argv[2], &size);
		if (input == 0)
			ft_putstr("Error\n");
		dict = read_file(argv[1], dict, input, size);
		print_dict(dict, input, size);
	}
}