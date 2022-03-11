/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:37:20 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 13:37:20 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)		// andere Schreibweise von malloc + setzt allokalisierten Speicher sofort 0
{
	void	*ptr;

	ptr = (void *)malloc(num * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int idx, * ptr, sum = 0;
// 	ptr = ft_calloc(10, sizeof(int));
// 	if (ptr == NULL) 
// 	{
// 		printf("calloc Error! memory not allocated.");
// 		exit(0);
// 	}
// 	printf("calloc Building and calculating the sequence sum of the first 10 terms\n");
// 	for (idx = 0; idx < 10; ++idx) 
// 	{
// 		* (ptr + idx) = idx;
// 		sum += * (ptr + idx);
// 	}
// 	printf("calloc Sum = %d\n", sum);
// 	free(ptr);
// }
