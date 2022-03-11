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
	int		**pipe_fd;
	pid_t	*pids;
	int		i;
	int		cmds;

	cmds = (argc - 3);
	if (argc < 5)
		exit(write(2, "Error: invalid arguments\n", 25));
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
