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

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr++ = 0;
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