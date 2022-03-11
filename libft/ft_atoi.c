/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:16:14 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/24 11:16:14 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)					// ascii to integer
{
	int		i;
	int		sign;
	long	temp;
	int		integer;							//keine malloc weil int schon bestimmte Größe hat (4 Byte)

	temp = 0;
	sign = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32) 		// testen ob Zeichen ein Space oder tab oder so ist
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		temp = temp * 10 + str[i] - '0';
		i++;
	}
	integer = temp * sign;											// hier wenn Eingabewert ist keine Zahl, Rückgabewert 0 * sign = 0
	return (integer);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char atoistr[] = "-8";

// 	printf("atoi %d", ft_atoi(atoistr));

// 	printf("\n");

// }