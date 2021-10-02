/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:07:21 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/30 19:44:16 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	where_path(t_pipe *start, char **envp, int flag)
{
	int		i;
	char	*buff;
	char	*buff2;

	i = 0;
	buff2 = NULL;
	while (start->path[i])
	{
		if (buff2)
			free (buff2);
		if (flag)
		{
			buff = ft_strjoin(start->path[i++], "/");
			buff2 = ft_strjoin(buff, start->command_first_split[0]);
			free(buff);
			execve(buff2, start->command_first_split, envp);
		}
		else
		{
			buff = ft_strjoin(start->path[i++], "/");
			buff2 = ft_strjoin(buff, start->command_second_split[0]);
			free(buff);
			execve(buff2, start->command_second_split, envp);
		}
	}
}

static void	processes(t_pipe *start, char **envp)
{
	if (start->id2)
	{
		dup2(start->fdpipe[1], 1);
		dup2(start->fd[0], 0);
		where_path(start, envp, 1);
		close(start->fdpipe[1]);
		close(start->fd[0]);
		ft_putstr_fd("Error: First command is unknown\n", 2);
	}
	else
	{
		dup2(start->fdpipe[0], 0);
		dup2(start->fd[1], 1);
		where_path(start, envp, 0);
		close(start->fdpipe[0]);
		close(start->fd[1]);
		ft_putstr_fd("Error: Second command is unknown\n", 2);
	}
	cleaning_company(start);
	exit (1);
}

void	what_if(t_pipe *start, char **envp)
{
	if (start->id2 != 0)
	{
		close(start->fd[1]);
		close(start->fdpipe[0]);
		processes(start, envp);
	}
	else
	{
		close(start->fd[0]);
		close(start->fdpipe[1]);
		processes(start, envp);
	}
}
