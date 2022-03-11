/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:59:01 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/23 12:59:01 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_lenght;
	size_t	src_lenght;
	size_t	len;

	dest_lenght = ft_strlen(dest);
	src_lenght = ft_strlen(src);
	len = size - 1 - dest_lenght;
	if (size <= dest_lenght)
		return (size + src_lenght);
	while (*dest)
		dest++;
	while (*src && len)
	{
		*dest++ = *src++;
		len--;
	}
	*dest = '\0';
	return (dest_lenght + src_lenght);		// The function returns the length of the string strlcat() tried to create; 
}											// if the return value is greater than or equal to size, data loss occurred.

// This function appends the null-terminated string src to the string dest, 
// copying at most size-strlen(dest)-1 from src, 
// and adds a terminating null byte to the result, unless size is less than strlen(dest).  
// This function fixes the buffer overrun problem of strcat(), but the caller must still handle the
// possibility of data loss if size is too small.  

