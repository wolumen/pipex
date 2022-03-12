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

int	open_file(char *filename, int mode, int i)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
			ft_error(-1, "access F_OK");
		if (access(filename, R_OK) == -1)
			ft_error(-1, "access R_OK");
		fd = open(filename, O_RDONLY);
		ft_error(fd, "open INFILE");
	}
	else if (i == 2)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		ft_error(fd, "open OUTFILE");
	}
	else if (i == 3)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
		ft_error(fd, "open OUTFILE");
	}
	return (fd);
}

void	change_std_io(char *infile, char *outfile, int i)
{
	int	fd;

	if (i == 2)
	{	
		fd = open_file(infile, INFILE, i);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}

	fd = open_file(outfile, OUTFILE, i);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	// printf("in open file\n");
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
			ft_error(-1, "pipe");
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
	pid_t	*pids;
	int		i;
	int		start;

	start = 2;
	// printf("amount of cmds: %d\n", size);
	// printf("argv[2]: %s\n", argv[2]);
	// printf("argv[start]: %s\n", argv[start]);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		start = 3;
	pids = (int *) malloc(size * sizeof(int));
	if (!pids)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(-1, "fork");
		if (pids[i] == 0)
		{
			redir_pipes(pipe_fd, size, i);
			close_unused_pipes(pipe_fd, size - 1);
			ft_exec(argv[i + start], envp);
		}
		i++;
	}
	return (pids);
}

void	ft_wait(int cmds)
{
	int i;

	i = 0;
	while (i < cmds)
	{	
		wait(NULL);
		i++;
	}	
}