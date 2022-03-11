/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:29:17 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 12:29:17 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)	// similar to strncpy(), but it copies at most
																// size-1 bytes to dest, always adds a terminating null byte, 
																// and does not pad the destination with (further) null bytes
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size -1))			// -1 allows a terminating null byte
		{
			dest[i] = src[i];					// hier wird kopiert
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])								// i wird hochgezählt weil return ist Länge von src
		i++;
	return (i);									// return der Funktion ist die Länge von src, wodurch das Abschneiden leicht erkannt werden kann: 
}												// if der Rückgabewert ist größer oder gleich size, Kürzung aufgetreten

// #include <stdio.h>

// int	main(void)
// {
// 	char 		buffer_dest[19];
// 	char 		str_src[]= "Hello there.";
// 	int			size;
// 	int 		r;

// 	size = 0;
// 	r = ft_strlcpy(buffer_dest, str_src, size);
// 	printf("Copied %d characters of %s, which lenght is %d, into %s\n", size, str_src, r, buffer_dest);
// }