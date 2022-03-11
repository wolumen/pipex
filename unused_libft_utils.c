/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:37:27 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/03 18:37:27 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == sep)
			count++;
	}
	tab = malloc(sizeof(char *) * (count + 2));		// warum + 2 ? -> 1str mehr als Delimeter und +1 für NULL ans Ende setzen
	if (tab == NULL)
		ft_error(errno, "malloc split");			// funktioniert Errno hier ? 
	tab[count + 1] = NULL;							// NULL ans Ende des Arrays für execve, + 1 weil Index beginnt bei 0
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = ft_strndup(str, j);
		str = str + j + 1;
	}
	return (tab);
}

char	*ft_strndup(char *str, unsigned int n)
{
	char			*duped;
	unsigned int	i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	if (duped == NULL)
		ft_error(errno, "malloc ft_strndup");
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
	// RETRUN:
	// 0	Die verglichenen Strings sind bis zum angegebenen Zeichen identisch
	// <0>	Die verglichenen Strings sind nicht identisch
}
