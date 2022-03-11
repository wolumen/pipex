/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:00:57 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 11:00:57 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)		// The bzero() function places n 0 bytes in the area pointed to by s
{
	char *ptr;							// TODO warum braucheich einen char pointer?

	ptr = s;							// geht nur weil *s void ist
	while (n)
	{
		*ptr++ = 0;						// // statt neuen char pointer clean gänge auch s casten = *(char *)s++ = 0;
		n--;
	}
}

// #include <stdio.h>

// int	main(void)
// {	
// 	char 		arr1[10];
// 	int 		i = 0;
//
// 	ft_bzero(arr1, sizeof(char) * 10);
// 	while (i++ < 10)
// 		printf("%c", arr1[i]);
// 	printf("\n");
// }