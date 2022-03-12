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

	if (argc < 5)
		exit(write(2, "Error: invalid arguments\n", 25));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		ft_here_doc(argv[2]);
		i = 3;
	}
	else	
	{
		i = 2;												// argv[i] ist erster cmd
	}
	change_std_io(argv[1], argv[argc - 1], i);
	pipe_fd = open_pipes(argc - i - 2);
	pids = process_forks(pipe_fd, argc - i - 1, argv, envp);
	close_unused_pipes(pipe_fd, argc - i - 2);
	ft_wait(argc - i - 1);											// wait cmds oder wait pids?
	free(pids);
	delete_fd_array(pipe_fd, argc - i - 2);
	return (0);
}
