/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:19:16 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/10 12:19:16 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, unsigned int n)
{
	char			*duped;
	unsigned int	i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	if (duped == NULL)
		return (NULL);
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}
