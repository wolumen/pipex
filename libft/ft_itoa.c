/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:31:48 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/25 16:31:48 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *str, unsigned int number, long int len)
{		
	if (number == 0)											
		str[0] = '0';
	while (number > 0)									// number muss größer > 0 weil Schleife sonst endlos läuft ( 0 ist Abbruchkriterium, darum n == 0 Abfrage in Zeile 51)
	{													
		str[len--] = 48 + (number % 10);				// Stringende, Zahl wird von hinten nach vorne geschrieben
		number = number / 10;							// von hinten schreiben und in der exakten Länge schütz das '-' im String das schon gesetzt wurde falls Zahl negativ
	}
	return (str);
}

static long int	ft_len(int n)
{
	int					len;

	len = 0;
	if (n <= 0)
		len = 1;										//len = 1 weil ein Zeichen für das Vorzeichen - bei n < 0
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*str;
	long int			len;
	unsigned int		number;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));		// Speicher für den Return string wird allokalisiert
	if (!(str))
		return (NULL);
	str[len--] = '\0';									// schreibe sofort \0 ans Ende vom neuen string (index von 0-2, darum an Stelle 3 \0), danach wird len -1 gerechnet damit ft_array von hinten anfangen kann zu schreiben								
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';									// wenn Zahl negativ, erste Stelle im String wird mit - besetzt
	}
	else
		number = n;
	str = ft_array(str, number, len);					// hier wird der leere str an ft_array zum schreiben übergeben
	return (str);
}

// putnbr gibt string aus. itoa gibt string zurück, zum Weiterarbeiten