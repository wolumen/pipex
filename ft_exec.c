/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:31:28 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/07 09:31:28 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *cmd, char *envp[])
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (chr_in_str(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], envp);
	if (execve(path, args, envp) == -1)						// programm endet hier wenn execve ausgeführt werden kann
		ft_error("execve");
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && chr_in_str(path, ':') > -1)			// wenn : gefunden
	{
		dir = ft_strndup(path, chr_in_str(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += chr_in_str(path, ':') + 1;
	}
	write(STDERR_FILENO, cmd, chr_in_str(cmd, 0));
	write(STDERR_FILENO, " - command not found\n", 21);
	exit (127);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (chr_in_str(path, 0) + chr_in_str(bin, 0) + 2));
	if (joined == NULL)
		ft_error("joined malloc");
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

int	chr_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);				// idx an der char erste mal gefunden
	return (-1);				// wenn char nicht gefunden -1 zurück
}
