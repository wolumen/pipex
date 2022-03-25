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
			ft_error(-1, filename);
		if (access(filename, R_OK) == -1)
			ft_error(-1, filename);
		fd = open(filename, O_RDONLY);
		ft_error(fd, filename);
	}
	else if (i == 2)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		ft_error(fd, filename);
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
		ft_error(fd, filename);
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

void	process_forks(int **pipe_fd, int size, char **argv, char **envp)
{
	pid_t	*pids;
	int		i;

	// printf("amount of childs: %d\n", size);
	// printf("argv[2]: %s\n", argv[2]);
	// printf("argv[start]: %s\n", argv[start]);
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
			ft_exec(argv[i], envp);
			delete_fd_array(pipe_fd, size -1);
			free(pids);
			// fprintf(stderr, "if ft_exec failed I'm executed\n");	
			exit (127);
		}
		i++;
	}
	free(pids);
}

void	ft_wait(int cmds)
{
	int	i;

	i = 0;
	while (i < cmds)
	{	
		wait(NULL);
		i++;
	}	
}
