/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:36:03 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/07 09:36:03 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errno_num, char *str)
{
	printf("Errno: %d in fct %s\n", errno_num, str);
	perror("Error in fct ");
	exit(EXIT_FAILURE);
}

int	**create_fd_array(int size)
{
	int	**pipe_fd;
	int	i;

	pipe_fd = (int **)malloc(size * sizeof(int));
	if (!pipe_fd)
		exit (EXIT_FAILURE);
	i = 0;
	while (i <= size)
	{
		pipe_fd[i] = (int *)malloc(2 * sizeof(int));
		if (!pipe_fd)
			exit (EXIT_FAILURE);
		i++;
	}
	return (pipe_fd);
}

void	delete_fd_array(int **pipe_fd, int size)
{
	while (size >= 0)
		free(pipe_fd[size--]);
	free(pipe_fd);
}

void	close_unused_pipes(int **pipe_fd, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}
