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

int	openfile(char *filename, int mode)
{
	int	fd;

	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
			ft_error(errno, "access F_OK");

		if (access(filename, R_OK) == -1)
			ft_error(errno, "access R_OK");

		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_error(errno, "open INFILE");
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd == -1)
			ft_error(errno, "open OUTFILE");
	}
	return (fd);
}

void	ft_error(int errno_num, char *str)
{
	printf("Errno: %d in fct %s\n", errno_num, str);
	perror("Error in fct ");
	exit(EXIT_FAILURE);
}

void	ft_exec(char *cmd, char *envp[])
{
	char	**args;
	char	*path;

	args = str_split(cmd, ' ');
	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = getPath(args[0], envp);
	execve(path, args, envp);			// programm endet hier wenn execve ausgeführt werden kann
	ft_error(errno, "execve");
}

char	*getPath (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && str_ncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1) 	// wenn : gefunden
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}

char	*path_join (char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (str_ichr(path, 0) + str_ichr(bin, 0) + 2));
	if (joined == NULL)
		ft_error(errno, "joined malloc");
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}