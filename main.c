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


void open_pipes(int pipe_fd[][2], int size)
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
	int pids[COMMANDS];					// für jeden cmd ein child
	int	pipe_fd[COMMANDS - 1][2];		// zwischen zwei cmd eine pipe
	int i;

	if (argc < 5)
	{
		write(STDERR_FILENO, "ERROR ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
		exit(EXIT_FAILURE);
	}	

	change_std_io(argv[1], argv[argc - 1]);

	// pipes öffnen (eine weniger als cmds)
	open_pipes(pipe_fd, COMMANDS - 1);

	// processe erstellen (einen je cmd)
	i = 0;
	while (i < COMMANDS)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(errno, "fork");
		if (pids[i] == 0)
		{
			// child [i] process
			// break or ft_child_stuff();

			if (i == 0)
			{
				// Child process 1
				dup2(pipe_fd[i][1], STDOUT_FILENO);
				// close all unused pipes in a loop
				close_unused_pipes(pipe_fd, COMMANDS - 1);
				ft_exec(argv[i + 2], envp);				
			}
			else if (i == COMMANDS - 1)
			{
				// Child process letzter
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				// close all unused pipes in a loop
				close_unused_pipes(pipe_fd, COMMANDS - 1);
				ft_exec(argv[i + 2], envp);				
			}
			else
			{
				// Child processes between
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				dup2(pipe_fd[i][1], STDOUT_FILENO);
				// close all unused pipes in a loop
				close_unused_pipes(pipe_fd, COMMANDS - 1);
				ft_exec(argv[i + 2], envp);					
			}
		}
		i++;
	}


	// close all unused pipes in a loop
	close_unused_pipes(pipe_fd, COMMANDS - 1);

	// wait for the children in a loop
	i = 0;
	while(i < COMMANDS)
	{	
		wait(NULL); 
		// waitpid(pids[i], NULL, 0);
		i++;
	}


	return (0);
}



// int open_pipes(int argc)
// {
// 	int	i;

// 	i = 0;
// 	while (i < COMMANDS -1)
// 	{
// 		if (pipe(pipe_fd[i]) == -1)
// 			ft_error(errno);
// 	}
// }