/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:58 by yalp              #+#    #+#             */
/*   Updated: 2024/12/16 16:34:01 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char **path;
	int	i;

	i = 0;
	while (ft_strcmp(env[i], "PATH=", 5))

	return (path);
}

char	*ret_path(char **env)
{
	int	i;
	char	*path;

	i = 0;
	while (env[i])
	{
	path = ft_strjoin(path, env[i]);
	i++;
	}
	return (path);
}

