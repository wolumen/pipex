/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:09:53 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/25 11:09:53 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_find_next_str(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int	ft_count_splits_str(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str = ft_find_next_str(str, c, 1);
		if (*str != '\0')
		{
			count++;
			str = ft_find_next_str(str, c, 0);
		}
	}
	return (count);
}

static void	*ft_tabledel(char **array, int i)
{
	int	x;

	x = 0;
	if (array)
	{
		while (x < i)
		{
			free(array[x]);
			x++;
		}
		free(array);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_splits_str(s, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_find_next_str(s, c, 1);
		if (*s != '\0')
		{
			next = ft_find_next_str(s, c, 0);
			result[i] = ft_substr(s, 0, next - s);
			if (result[i] == NULL)
				return (ft_tabledel(result, i));
			i++;
			s = next;
		}
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char			split_str[] = "alles wird gut";
// 	char 			split_c = ' ';
// 	char			**splitted;
// 	char			**freesplit;
// 	splitted = ft_split(split_str, split_c);
// 	freesplit = splitted;
// 	while (*splitted)
// 	{
// 		printf("split: %s\n", *splitted);
// 		splitted++;
// 	}			
// 	free(freesplit);
// 	splitted = NULL;
// }