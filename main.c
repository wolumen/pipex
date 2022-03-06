/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:15:11 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/03 13:15:11 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_pipes(int pipe_fd[][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pipe(pipe_fd[i]) == -1)
			ft_error(errno, "pipe");
		i++;
	}
}

void	close_unused_pipes(int pipe_fd[][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}

void	process_forks(int pipe_fd[][2], int size, char *argv[], char *envp[])
{
	int	pids[size];
	int	i;

	i = 0;
	while (i < size)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(errno, "fork");
		if (pids[i] == 0)
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
			close_unused_pipes(pipe_fd, size - 1);
			ft_exec(argv[i + 2], envp);
		}
		i++;
	}
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

int	main(int argc, char *argv[], char *envp[])
{
	int	pipe_fd[COMMANDS - 1][2];
	int	i;

	if (argc < 5)
	{
		write(STDERR_FILENO, "ERROR ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
		exit(EXIT_FAILURE);
	}	
	change_std_io(argv[1], argv[argc - 1]);
	open_pipes(pipe_fd, COMMANDS - 1);
	process_forks(pipe_fd, COMMANDS, argv, envp);
	close_unused_pipes(pipe_fd, COMMANDS - 1);
	i = COMMANDS;
	while (--i)
		wait(NULL);
	return (0);
}
