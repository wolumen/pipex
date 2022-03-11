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
# include <unistd.h>		// für close, access, execve, pipe, fork
# include <errno.h>
# include <sys/stat.h>		// für S_IRWXU in open,
# include <sys/types.h>
# include <sys/wait.h>		// für waitpid

# define INFILE 0
# define OUTFILE 1

// pipex.c
int		openfile(char *filename, int mode);
void	change_std_io(char *infile, char *outfile);
int		**open_pipes(int size);
int		*process_forks(int **pipe_fd, int size, char *argv[], char *envp[]);
// pipex_utils.c
void	ft_error(char *str);
int		**allocate_fd_array(int size);
void	delete_fd_array(int **pipe_fd, int size);
void	close_unused_pipes(int **pipe_fd, int size);
void	redir_pipes(int **pipe_fd, int size, int i);
// ft_exec.c
void	ft_exec(char *cmd, char *envp[]);
char	*get_path(char *cmd, char **env);
char	*path_join(char *path, char *bin);
int		chr_in_str(char *str, char c);
// libft_utils.c
char	**ft_split(char *str, char sep);
char	*ft_strndup(char *str, unsigned int n);
int		ft_strncmp(char *str1, char *str2, int n);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);

char	*ft_strdup(const char *str1);



// enum error_handle
// {
// 	ARGS_ERR = -2,
// 	PIPE_ERR = -3,
// 	FORK_ERR = -4,
// 	CMD_ERR = -5,
// 	OPEN_ERR = -6,
// };

#endif