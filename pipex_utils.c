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

char	**str_split (char *str, char sep)
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
	tab = malloc(sizeof(char *) * (count + 2));
	if (tab == NULL)
		ft_error(errno);							// funktioniert Errno hier ? 
	tab[count + 1] = NULL;							// NULL ans Ende des Arrays für execve
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = str_ndup(str, j);
		str = str + j + 1;
	}
	return (tab);
}

char	*str_ndup (char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	if (duped == NULL)
		ft_error(errno);
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int	str_ichr (char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);				// idx an der char erste mal gefunden
	return (-1);				// wenn char nicht gefunden -1 zurück
}

int	str_ncmp (char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}