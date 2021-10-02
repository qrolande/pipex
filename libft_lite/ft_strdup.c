/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:03:13 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/28 20:03:15 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		l;
	int		i;

	i = 0;
	l = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	while (l > i)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
