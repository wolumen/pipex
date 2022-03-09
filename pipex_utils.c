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

int	**allocate_fd_array(int pipes)
{
	int	**pipe_fd;
	int	i;

	// printf("amount of pipes: %d\n", pipes);
	pipe_fd = malloc(sizeof(int*) * pipes);
	if (!pipe_fd)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < pipes)
	{
		pipe_fd[i] = malloc(sizeof(int) * 2);
		if (!pipe_fd)
			exit (EXIT_FAILURE);
		i++;
	}
	// int j;
    // for (i = 0; i < pipes; i++) {
    //     for (j = 0; j < 2; j++) {
    //         printf("%d ", pipe_fd[i][j]);
    //     }
    //     printf("\n");
    // }
	return (pipe_fd);
}

void	delete_fd_array(int **pipe_fd, int pipes)
{
	int	i;

	i = 0;
	while (i < pipes)
	{
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}

void	redir_pipes(int **pipe_fd, int size, int i)
{
	if (i == 0)
		dup2(pipe_fd[i][1], STDOUT_FILENO);
	else if (i == size - 1)
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
	else
	{
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(pipe_fd[i][1], STDOUT_FILENO);
	}
}

void	close_unused_pipes(int **pipe_fd, int pipes)
{
	int	i;

	i = 0;
	while (i < pipes)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}
