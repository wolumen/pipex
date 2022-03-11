/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:34:50 by jpreissn          #+#    #+#             */
/*   Updated: 2021/11/26 12:34:50 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)		// setzt immer nur einen char. string schreiben -> putstr
{
	write (fd, &c, 1);					// fd 0 = stdin, fd 1 = stdout, fd 2 = stderr
}
