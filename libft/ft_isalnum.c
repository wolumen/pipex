/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:27:58 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/22 10:27:58 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)					// is alphanumeric
{
	if (c > 64 && c < 91)				// wenn A - Z return true/1
		return (1);
	else if (c > 96 && c < 123)			// wenn a -z return true/1
		return (1);
	else if (c > 47 && c < 58)			// wenn 0 -9 return true/1
		return (1);
	else
		return (0);						// wenn alles andere return false/0
}
