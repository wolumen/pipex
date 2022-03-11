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
		while (*str != '\0' && *str == c)		// schließt aus das Delimeter am Anfang ist, weil dann nichts zu teilen
			str++;								// wenn Delimeteram Anfang string wird weitergezählt
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_count_splits_str(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		str = ft_find_next_str(str, c, 1);		// checked erstmal ob Delimeter am Anfang ist, weil dann nichts zu teilen
		if (*str != '\0')
		{
			count++;
			str = ft_find_next_str(str, c, 0);	// danach zurück in while Schleife, erstmal den Delimeter überspringen dann ins IF das nächste Wort counten
		}
	}
	return (count);
}

static void			*ft_tabledel(char **array, int i)		// aufräumen wenn Programm fehler wirft
{
	int x;

	x = 0;
	if (array)
	{
		while (x < i)
		{
			free(array[x]);									// erst strings freigeben
			x++;
		}
		free(array);										// dann Liste von pointern auf die strings
	}
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char		**result;										// **result weil ein Array of strings
	int			i;												// erster * für Platz im Array, zweiter ** für Platz im String
	const char	*next;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_splits_str(s, c) + 1));			// zuerst splits zählen und genugpointer allocalisieren
	if (result == NULL)											// Abfrage ob das Memoryallokalisieren funktioniert hat
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_find_next_str(s, c, 1);							// hier wird der Delimeter übersprungen
		if (*s != '\0')
		{
			next = ft_find_next_str(s, c, 0);					// pointer zum Anfang jedes neuen strings
			result[i] = ft_substr(s, 0, next - s);				// returns new allocated substring at index with specific lenght from s
			if (result[i] == NULL)								// wenn Alokalisierungsproblem bei substr auftaucht gibt es NULL in result
				return (ft_tabledel(result, i));				// aufräumen wenn Programm fehler wirft
			i++;												
			s = next;											
		}
	}
	result[i] = 0;												// return eine Liste von pointer auf strings
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
