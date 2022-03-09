/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:59:20 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/28 10:59:20 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
		{
			perror("access F_OK");
			return (0);
		}
		if (access(filename, R_OK) == -1)
		{
			perror("access R_OK");
			return (0);
		}
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_error(errno, "open INFILE");
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd == -1)
			ft_error(errno, "open OUTFILE");
	}
	return (fd);
}

void	change_std_io(char *infile, char *outfile)
{
	int	fd;

	fd = openfile(infile, INFILE);
	dup2(fd, STDIN_FILENO);
	close(fd);

	fd = openfile(outfile, OUTFILE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

int	**open_pipes(int pipes)
{
	int	**pipe_fd;
	int	i;

	pipe_fd = allocate_fd_array(pipes);
	i = 0;
	while (i < pipes)
	{
		if (pipe(pipe_fd[i]) == -1)
			perror("pipe");
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

int	*process_forks(int **pipe_fd, int size, char *argv[], char *envp[])
{
	int	*pids;
	int	i;
	// printf("amount of cmds: %d\n", size);
	pids = (int *) malloc(size * sizeof(int));
	if (!pids)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(errno, "fork");
		if (pids[i] == 0)
		{
			redir_pipes(pipe_fd, size, i);
			close_unused_pipes(pipe_fd, size - 1);
			ft_exec(argv[i + 2], envp);
		}
		i++;
	}
	return (pids);
}
