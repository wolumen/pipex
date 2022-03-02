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

int	openfile (char *filename, int mode);


int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;
	int pid1;
	int pid2;
	int pipe_fd[2];

	if (argc != 5)
	{
		write(STDERR_FILENO, "ERROR. Use executable like this: ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
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
	{
		perror("Error at piping");
		exit(EXIT_FAILURE);
	}


	if ((pid1 = fork()) == -1)
	{
		perror("Error at forking #1");
		exit(EXIT_FAILURE);
	}

	if (pid1 == 0)
	{
		// Child process 1 (grep)
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		if (execlp("grep", "grep", "pipe", NULL) == -1)
		{
			perror("Error at exec grep");
			exit(EXIT_FAILURE);
		}
	}
	

	if ((pid2 = fork()) == -1)
	{
		perror("Error at forking #2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		// Child process 2 (wc)
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		if (execlp("wc", "wc", "-l", NULL) == -1)
		{
			perror("Error at exec wc");
			exit(EXIT_FAILURE);
		}
	}

	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}


int	openfile (char *filename, int mode)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		if (access(filename, R_OK) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		
		if ((fd = open(filename, O_RDONLY)) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		return (fd);
	}
	else
	{
		if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1)
		{
			perror("unable to open/create outfile");
			exit(EXIT_FAILURE);			
		}
				return (fd);
	}
}
