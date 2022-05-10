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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char 		buffer_dest[19];
// 	char 		str_src[]= "Hello there.";
// 	int			size;
// 	int 		r;
// 	size = 0;
// 	r = ft_strlcpy(buffer_dest, str_src, size);
// 	printf("Copied %d characters of %s, which lenght is %d, 
// 		into %s\n", size, str_src, r, buffer_dest);
// }