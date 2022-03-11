/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:27:43 by jpreissn          #+#    #+#             */
/*   Updated: 2021/12/21 09:27:43 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_check_for_n(char *leftover);
char	*ft_line(char *leftover);
int		ft_char_is_n(char c);
char	*ft_after_n(char *leftover);

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*buf;
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_check_for_n(leftover[fd]) == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(buf));
		buf[bytes_read] = '\0';
		leftover[fd] = ft_strjoin(leftover[fd], buf);
	}
	free(buf);
	line = ft_line(leftover[fd]);
	leftover[fd] = ft_after_n(leftover[fd]);
	return (line);
}

int	ft_check_for_n(char *leftover)
{
	int	i;

	i = 0;
	if (!leftover)
		return (0);
	while (leftover[i])
	{
		if (leftover[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover || !leftover[0])
		return (NULL);
	while (leftover[i] != '\0' && leftover[i] != '\n')
		i++;
	i += ft_char_is_n(leftover[i]);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] != '\0' && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_char_is_n(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*ft_after_n(char *leftover)
{
	int		i;
	int		j;
	char	*after_newline;

	i = 0;
	j = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] != '\0' && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\0')
		return (ft_free(leftover));
	i = i + 1;
	after_newline = malloc(ft_strlen(leftover) - i + 1);
	if (!after_newline)
		return (NULL);
	while (leftover[i])
		after_newline[j++] = leftover[i++];
	after_newline[j] = '\0';
	free(leftover);
	return (after_newline);
}
