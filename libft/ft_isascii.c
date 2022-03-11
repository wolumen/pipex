/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:59:48 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 10:59:48 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)			// ö z.B. ist nicht in der Standart ASCII Tabelle
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
