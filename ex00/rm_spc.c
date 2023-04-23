/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_spc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhong <auhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:41:35 by ktomoya           #+#    #+#             */
/*   Updated: 2023/04/23 22:02:23 by auhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	else
		return (0);
}

int	find_len_no_space(char *str)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (str[idx] != '\0')
	{
		while (str[idx] != '\0' && str[idx] == ' ')
			++idx;
		while (str[idx] != '\0' && str[idx] != ' ')
		{
			++size;
			++idx;
		}
		if (str[idx] == '\0')
			break ;
		++size;
	}
	return (size);
}

char	*abs_rm_spc(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '\0')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*rm_spc(char *str)
{
	char	*end;
	char	*dest;
	char	*ret;

	end = str + ft_strlen(str) - 1;
	while (ft_isspace(*str))
		str++;
	while (ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	dest = (char *)malloc(sizeof(char) * (find_len_no_space(str) + 1));
	if (dest == NULL)
		return (NULL);
	ret = dest;
	while (*str)
	{
		while (*str != '\0' && ft_isspace(*str))
			str++;
		while (*str != '\0' && *str != ' ')
			*dest++ = *str++;
		if (*str != '\0')
			*dest++ = ' ';
	}
	*dest = '\0';
	return (ret);
}
