/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:23:48 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/28 20:23:53 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *) s;
	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}
