/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:46:04 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/11 13:46:04 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_lines(int *pipe_fd, char *delimeter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, delimeter, ft_strlen(delimeter)) == 0)
		{
			if (line)
				free(line);
			exit(0);
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	ft_here_doc(char *delimeter)
{
	int		pipe_fd[2];
	int		pid;

	if (pipe(pipe_fd) == -1)
		ft_error(1, "Error pipe here_doc");
	pid = fork();
	if (pid == 0)
		get_lines(pipe_fd, delimeter);
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		wait(NULL);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
