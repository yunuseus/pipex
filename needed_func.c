/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:58 by yalp              #+#    #+#             */
/*   Updated: 2024/12/18 16:08:25 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char **path;
	int	i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
		{
			path = ft_split(ft_strchr(env[i], '/'), ':');
			return (path);
		}
		i++;
	}
	return (path);
}

char	*ret_path(char **env, char *cmd)
{
	int	i;
	char	**path;
	char	*tmpath;
	char	*tpath;

	path = get_path(env);
	i = 0;
	while (path[i])
	{
		tmpath = ft_strjoin(path[i], '/');
		tpath = ft_strjoin(tmpath, cmd);
		free(tmpath);
		if (access(tpath, X_OK) == 0)
			return(tpath);
		else
			free(tpath);
	i++;
	}
	exit(EXIT_FAILURE);
}

void	pipex_run(char *cmd, char *env)
{

}
