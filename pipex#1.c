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

int	str_ichr (char *str, char c);
char	*str_ndup (char *str, unsigned int n);

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;
	int pid;

	if (argc == 5)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		if (access(argv[1], R_OK) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		
		if ((infile = open(argv[1], O_RDONLY)) == -1)
		{
			perror("unable to open infile");
			exit(EXIT_FAILURE);
		}
		if ((outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
							S_IRWXU, S_IRWXG, S_IRWXO)) == -1)
		{
			perror("unable to open/create outfile");
			exit(EXIT_FAILURE);			
		}
		dup2(infile, STDIN_FILENO),
		dup2(outfile, STDOUT_FILENO);

		// von hier an !jede Ausgabe ins Outfile!

		printf("test#2\n");
		// printf("envp: %s\n", envp); funktioniert nicht weil envp is char **
		printf("envp[0]:\n%s\n", envp[0]);
		printf("envp[16]:\n%s\n", envp[16]);
		printf("envp[16] + 5:\n%s\n", envp[16] + 5);

		char	*path;
		path = envp[16] + 5;	
		printf("der Path:\n%s\n", path);
		path += str_ichr(path, ':') + 1;
		printf("str_ichr: %d\n", str_ichr(path, ':'));
		printf("der Path:\n%s\n", path);

		char	*dir;
		dir = str_ndup(path, str_ichr(path, ':'));
		printf("str_ndup:\n%s\n", dir);


		// pipe anlegen
		if (pipe())




		close(infile);
		close(outfile);
	}
	else
		write(STDERR, "ERROR. Use executable like this: ./pipex file1 \"cmd1\" \"cmd2\" file2\n", 67);
}





int	str_ichr (char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);		// idx an der char erste mal gefunden
	return (-1);		// wenn char nicht gefunden -1 zurück
}

char	*str_ndup (char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}
