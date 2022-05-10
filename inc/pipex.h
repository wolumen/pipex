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

# include <stdio.h>			// printf, perror
# include <fcntl.h>			// open, 
# include <stdlib.h>		// EXIT_
# include <unistd.h>		// close, access, execve, pipe, fork
# include <string.h>		// strerror
# include <errno.h>
# include <sys/wait.h>		// wait, waitpid

# define INFILE 0
# define OUTFILE 1

// pipex.c
int		open_file(char *filename, int mode, int i);
void	change_std_io(char *infile, char *outfile, int i);
int		**open_pipes(int size);
void	process_forks(int **pipe_fd, int size, char **argv, char **envp);
void	ft_wait(int cmds);

// pipex_utils.c
void	ft_error(int i, char *str);
int		**allocate_fd_array(int size);
void	delete_fd_array(int **pipe_fd, int size);
void	close_unused_pipes(int **pipe_fd, int size);
void	redir_pipes(int **pipe_fd, int size, int i);

// ft_exec.c
void	ft_exec(char *cmd, char **envp);
char	*cmd_path(char *cmd, char **env);
char	*add_cmd_to_dir(char *path, char *bin);
int		chr_str(char *str, char c);

// ft_here_doc.c
void	ft_here_doc(char *delimeter);
void	get_lines(int *pipe_fd, char *delimeter);

// libft
char	**ft_split(char *str, char sep);
char	*ft_strndup(char *str, unsigned int n);
int		ft_strncmp(char *str1, char *str2, int n);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char const *s, int fd);

#endif