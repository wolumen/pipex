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
# include <unistd.h>		// für close, access
# include <string.h>		// strsplit..
# include <errno.h>
# include <sys/wait.h>		// für waitpid
# include <sys/stat.h>		// für S_IRWXU in open, 


# define INFILE 0
# define OUTFILE 1




#endif