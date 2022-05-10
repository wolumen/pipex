/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:31:28 by jpreissn          #+#    #+#             */
/*   Updated: 2022/03/07 09:31:28 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	int		i;

	args = ft_split(cmd, ' ');
	if (chr_str(args[0], '/') > -1)
		path = args[0];
	else
		path = cmd_path(args[0], envp);
	execve(path, args, envp);
	write(STDERR_FILENO, args[0], ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 21);
	i = 0;
	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	free(args);
}

char	*cmd_path(char *cmd, char **env)
{
	char	*path;
	char	**dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	dir = ft_split(path, ':');
	i = 0;
	while (dir[i])
	{
		bin = add_cmd_to_dir(dir[i], cmd);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		free(dir[i]);
		i++;
	}
	free(dir);
	return (cmd);
}

char	*add_cmd_to_dir(char *path, char *cmd)
{
	char	*bin;
	int		i;
	int		j;

	bin = malloc(sizeof(char) * (chr_str(path, '\0') + chr_str(cmd, '\0') + 2));
	if (bin == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (path[j])
		bin[i++] = path[j++];
	bin[i++] = '/';
	j = 0;
	while (cmd[j])
		bin[i++] = cmd[j++];
	bin[i] = '\0';
	return (bin);
}

int	chr_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
