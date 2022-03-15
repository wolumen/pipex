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

void	*ft_memchr(const void *s, int c, size_t n)
{								
	unsigned int	i;
	unsigned char	*str;
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
