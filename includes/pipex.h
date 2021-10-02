/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:22:50 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/28 21:31:50 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
	int			id;
	int			id2;
	int			fd[2];
	char		**path;
	int			fdpipe[2];
	char		*command_first;
	char		*command_second;
	char		**command_first_split;
	char		**command_second_split;
}				t_pipe;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	what_if(t_pipe *start, char **envp);
void	cleaning_company(t_pipe *start);
void	valid_fd(int fd, char *str);
void	errorout(int i);

#endif