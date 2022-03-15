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

	if (argc < 5)
		exit(write(2, "Error: invalid arguments\n", 25));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_here_doc(argv[2]);
		i = 3;
	}
	else
		i = 2;														// argv[i] is first cmd
	cmds = argc - i;
	change_std_io(argv[1], argv[argc - 1], i);
	pipe_fd = open_pipes(cmds - 2);
	pids = process_forks(pipe_fd, cmds - 1, &argv[i], envp);
	close_unused_pipes(pipe_fd, cmds - 2);
	ft_wait(cmds - 1);											// wait cmds oder wait pids?
	free(pids);
	delete_fd_array(pipe_fd, cmds - 2);							// free pipe_fd array
	return (0);
}
