/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:00:41 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/28 11:00:41 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>			// für printf
# include <fcntl.h>			// für open, 
# include <stdlib.h>		// für EXIT_
# include <unistd.h>		// für close, access, execve
# include <string.h>		// strsplit..
# include <errno.h>
# include <sys/stat.h>		// für S_IRWXU in open,
# include <sys/types.h>
# include <sys/wait.h>		// für waitpid
 


# define INFILE 0
# define OUTFILE 1


int		openfile(char *filename, int mode);
void	ft_error(int errno_num);
void	ft_exec(char *cmd, char *envp[]);
char	**str_split (char *str, char sep);
char	*str_ndup (char *str, unsigned int n);
int		str_ichr (char *str, char c);
char	*getPath (char *cmd, char **env);
int		str_ncmp (char *str1, char *str2, int n);
char	*path_join (char *path, char *bin);






// enum error_handle
// {
// 	ARGS_ERR = -2,
// 	PIPE_ERR = -3,
// 	FORK_ERR = -4,
// 	CMD_ERR = -5,
// 	OPEN_ERR = -6,

// };


#endif