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

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;
	int pids[COMMANDS];					// für jeden cmd ein child
	int	pipe_fd[COMMANDS - 1][2];		// zwischen zwei cmd eine pipe
	int i;
	int	j;

	if (argc != 5)
	{
		write(STDERR_FILENO, "ERROR ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
		exit(EXIT_FAILURE);
	}	

	infile = openfile(argv[1], INFILE);
	outfile = openfile(argv[argc -1], OUTFILE);

	//stdin und stdout ersetzten durch die files und alte fd für die files schließen
	// ab hier Ausgabe ins OUTFILE!
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(infile);
	close(outfile);


	// pipes öffnen (eine weniger als cmds)
	i = 0;
	while (i < COMMANDS - 1)
	{
		if (pipe(pipe_fd[i]) == -1)
			ft_error(errno, "pipe");
		i++;
	}


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
				j = 0;
				while (j < COMMANDS - 1)
				{
					close(pipe_fd[j][0]);					// kann ich das auch in einer Zeile ?
					close(pipe_fd[j][1]);
					j++;
				}
				ft_exec(argv[i + 2], envp);				
			}
			else if (i == COMMANDS - 1)
			{
				// Child process letzter
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				// close all unused pipes in a loop
				j = 0;
				while (j < COMMANDS - 1)
				{
					close(pipe_fd[j][0]);					// kann ich das auch in einer Zeile ?
					close(pipe_fd[j][1]);
					j++;
				}
				ft_exec(argv[i + 2], envp);				
			}
			else
			{
				// Child processes between
				dup2(pipe_fd[i - 1][0], STDIN_FILENO);
				dup2(pipe_fd[i][1], STDOUT_FILENO);
				// close all unused pipes in a loop
				j = 0;
				while (j < COMMANDS - 1)
				{
					close(pipe_fd[j][0]);					// kann ich das auch in einer Zeile ?
					close(pipe_fd[j][1]);
					j++;
				}
				ft_exec(argv[i + 2], envp);					
			}
		}
		i++;
	}


	// close all unused pipes in a loop
	j = 0;
	while (j < COMMANDS - 1)
	{
		close(pipe_fd[j][0]);					// kann ich das auch in einer Zeile ?
		close(pipe_fd[j][1]);
		j++;
	}

	// wait for the children in a loop
	i = 0;
	while(i < COMMANDS)
		wait(NULL); 


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