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

int	main(int argc, char **argv, char **envp)
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
		i = 2;														// argv[i] is first cmds
	cmds = argc - i - 1;											// -1 for last file argument
	change_std_io(argv[1], argv[argc - 1], i);
	pipe_fd = open_pipes(cmds - 1);									// -1 for one pipe less than commands
	pids = process_forks(pipe_fd, cmds, &argv[i], envp);	
	close_unused_pipes(pipe_fd, cmds - 1);
	ft_wait(cmds);
	free(pids);
	delete_fd_array(pipe_fd, cmds - 1);								// free pipe_fd array
	return (0);
}
