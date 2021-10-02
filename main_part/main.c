/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:09:29 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/30 18:59:11 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	if_path(t_pipe *start, char **envp)
{
	int	res;

	res = 0;
	while (ft_strnstr(envp[res], "PATH=", 5) == 0)
		res++;
	if (envp[res] == 0)
		errorout(4);
	start->path = ft_split(envp[res] + 5, ':');
}

static void	init_all(char **argv, t_pipe *start)
{
	start->fd[0] = open(argv[1], O_RDONLY);
	valid_fd(start->fd[0], argv[1]);
	start->fd[1] = open(argv[4], O_TRUNC | O_RDWR | O_CREAT, 0666);
	valid_fd(start->fd[1], argv[4]);
	if (pipe(start->fdpipe) == -1)
		errorout(2);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		errorout(3);
	start->command_first = ft_strdup(argv[2]);
	start->command_second = ft_strdup(argv[3]);
	start->command_first_split = ft_split(argv[2], ' ');
	start->command_second_split = ft_split(argv[3], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	start;

	if (argc == 5)
	{
		init_all(argv, &start);
		if_path(&start, envp);
		start.id = fork();
		if (start.id == 0)
		{
			start.id2 = fork();
			if (start.id2)
				what_if(&start, envp);
			else
				what_if(&start, envp);
		}
		wait(NULL);
		cleaning_company(&start);
	}
	else
		errorout(1);
	return (0);
}
