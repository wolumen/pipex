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
	int	**pipe_fd;
	int	*pids;
	int	i;
	int	cmds;

	cmds = (argc - 3);
	pipe_fd = NULL;
	if (argc < 5)
	{
		write(STDERR_FILENO, "ERROR ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
		exit(EXIT_FAILURE);
	}
	change_std_io(argv[1], argv[argc - 1]);
	pipe_fd = open_pipes(cmds - 1);
	pids = process_forks(pipe_fd, cmds, argv, envp);
	close_unused_pipes(pipe_fd, cmds - 1);
	i = cmds;
	while (i--)
		wait(NULL);
	free(pids);
	delete_fd_array(pipe_fd, cmds - 1);
	return (0);
}
