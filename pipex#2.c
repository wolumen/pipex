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

int		openfile(char *filename, int mode);
void	ft_error(int errno_num);

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
		// Child process 1 (grep)
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		if (execlp("grep", "grep", "pipe", NULL) == -1)
			ft_error(errno);
	}
	

	pid2 = fork();
	if (pid2 == -1)
		ft_error(errno);

	if (pid2 == 0)
	{
		// Child process 2 (wc)
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		if (execlp("wc", "wc", "-l", NULL) == -1)
			ft_error(errno);

	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}


int	openfile(char *filename, int mode)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
			ft_error(errno);

		if (access(filename, R_OK) == -1)
			ft_error(errno);

		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_error(errno);
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd == -1)
			ft_error(errno);
	}
	return (fd);
}


void	ft_error(int errno_num)
{
	printf("Ärrno: %d\n", errno_num);
	perror("unAble in fct ");
	exit(EXIT_FAILURE);
}


