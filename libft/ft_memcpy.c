/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:07:57 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 17:07:57 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)		// n − is the number of bytes to be copied.
{
	char	*d;					// char nicht weil man einen char sucht sondern weil ein char ein Byte ist und man Byte für Byte sucht
	char	*s;
	unsigned int	i;

	i = 0;
	d = (char *) dest;					// hier kein unsigned char weil es nicht im man steht
	s = (char *) src;
	if (dest == src || !n)				// dest == src ist Abfrage der Adressen beider
		return (dest);					// steht nicht im Handbuch
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char 		str2[] = "Start stop";
	
// 	printf("Before ft_memcpy %s\n", str2);
// 	ft_memcpy(str2, str2 + 6, 4 * sizeof(char));
// 	printf("After ft_memcpy %s\n", str2);
// }
