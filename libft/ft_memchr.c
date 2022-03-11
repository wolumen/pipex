/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:10:39 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 18:10:39 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)	// searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str.	
{													// untersucht das was man rein gibt Byte für Byte									
	unsigned int	i;
	unsigned char	*str;							// char nicht weil man einen char sucht sondern weil ein char ein Byte ist und man Byte für Byte sucht
	unsigned char	d;

	d = (unsigned char) c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int arr[] = {3, 4, 5, 6};

// 	if (ft_memchr(arr, 1, sizeof(int) * 4))
// 		printf("memchr Found the byte\n");
// 	else
// 		printf("memchr Did not find the byte\n");
// }
