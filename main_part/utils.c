/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:35:50 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/28 20:33:09 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	errorout(int i)
{
	if (i == 1)
		ft_putstr_fd("Incorrect number of arguments\n", 2);
	if (i == 2)
		ft_putstr_fd("Pipe creation error\n", 2);
	if (i == 3)
		ft_putstr_fd("Error: not valid command - \"\"\n", 2);
	if (i == 4)
		ft_putstr_fd("Where is the path?\n", 2);
	exit(1);
}

void	valid_fd(int fd, char *str)
{
	int	res;

	res = read(fd, 0, 0);
	if (res < 0)
	{
		ft_putstr_fd("Can't read file \"", 2);
		ft_putstr_fd(str, 2);
		write(2, "\"\n", 2);
		exit (2);
	}
	if (fd < 0)
	{
		ft_putstr_fd("Can't open file \"", 2);
		ft_putstr_fd(str, 2);
		write(2, "\"\n", 2);
		exit (3);
	}
}

static void	ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(str[i++]);
	free(str);
}

void	cleaning_company(t_pipe *start)
{
	int	i;

	i = 0;
	while (start->command_first_split[i])
		i++;
	ft_free(start->command_first_split, i);
	i = 0;
	while (start->command_second_split[i])
		i++;
	ft_free(start->command_second_split, i);
	i = 0;
	while (start->path[i])
		i++;
	ft_free(start->path, i);
	free(start->command_first);
	free(start->command_second);
}
