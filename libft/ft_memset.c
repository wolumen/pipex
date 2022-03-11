/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:32:09 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 16:32:09 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)		// setzt n Bytes in einem Array zu c
{													// fängt vorne an 
	unsigned char	*a;
	unsigned int	i;

	i = 0;
	a = (unsigned char *)str;
	while (i < n)
	{
		*a = (unsigned char) c;				
		a++;
		i++;
	}
	return (str);
}
