/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:03:12 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 18:03:12 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)	// memmove copies source first to a buffer and then to the dest
{															// safer then memcpy when memory from dest and src is overlapping
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)												// Zieladresse kommt nach Sourceadresse
	{														// dest könnte innerhalb source liegen
		while (n > 0)
		{
			d[n - 1] = s[n - 1];							// wird von hinten nach vorn geschrieben, somit wird sorc nicht beim kopieren überschrieben
			n--;
		}	
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}


    //    The memmove() function copies n bytes from memory area src to
    //    memory area dest.  The memory areas may overlap: copying takes
    //    place as though the bytes in src are first copied into a
    //    temporary array that does not overlap src or dest, and the bytes
    //    are then copied from the temporary array to dest.