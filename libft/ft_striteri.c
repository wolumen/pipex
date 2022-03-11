/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:34:00 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/25 18:34:00 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return;
	while (*s)
		f(i++, s++);
}

// strmapi & striteri wenden Funktionen auf jedes Element eines strings an. 
// strmapi gibt das Ergebnis als neuen string zurück. striteri überscheibt string.
