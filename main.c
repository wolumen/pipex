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
	int	pid1;
	int	pid2;
	int	pipe_fd[2];

	if (argc != 5)
	{
		write(STDERR_FILENO, "ERROR ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
		exit(EXIT_FAILURE);
	}	

	infile = openfile(argv[1], INFILE);
	outfile = openfile(argv[4], OUTFILE);

	//stdin und stdout ersetzten durch die files und alte fd für die files schließen
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(infile);
	close(outfile);

	if (pipe(pipe_fd) == -1)
		ft_error(errno);


	pid1 = fork();
	if (pid1 == -1)
		ft_error(errno);


	if (pid1 == 0)
	{
		// Child process 1
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		ft_exec(argv[2], envp);
	}
	

	pid2 = fork();
	if (pid2 == -1)
		ft_error(errno);

	if (pid2 == 0)
	{
		// Child process 2
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		ft_exec(argv[3], envp);
	}

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}