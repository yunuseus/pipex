/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:58 by yalp              #+#    #+#             */
/*   Updated: 2024/12/19 16:24:27 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char **path;
	int	i;

	path = NULL;
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
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
	char	**path;
	char	*tmpath;
	char	*tpath;


	path = get_path(env);
	while (path && *path)
	{
		tmpath = ft_strjoin(*path, "/");
		tpath = ft_strjoin(tmpath, cmd);
		free(tmpath);
		if (access(tpath, X_OK) == 0)
			return(tpath);
		else
			free(tpath);
		path++;
	}
	exit(EXIT_FAILURE);
}

void	ft_pipex_run(char *cmd, char **env)
{
	char	*path;
	char	**cmds;

	
	cmds = ft_split(cmd, ' ');
	if (ft_strchr(cmds[0], '/'))
	{
		path = cmds[0];
		if (access(cmds[0], X_OK) == -1)
		{
			free(path);
			free(cmds);
			
			exit(EXIT_FAILURE);
		}
	}
	else
		path = ret_path(env, cmds[0]);
	execve(path, cmds, env);
	free(cmds);
}
