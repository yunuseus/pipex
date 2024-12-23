/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:58 by yalp              #+#    #+#             */
/*   Updated: 2024/12/23 19:12:28 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_puterr(char *a, int b)
{
	if (b == 1)
	{
		ft_putstr_fd(a, 2);
		ft_putendl_fd(": Permission denied", 2);
		free(a);
		exit (126);
	}
	if (b == 2)
	{
		ft_putstr_fd(a, 2);
		ft_putendl_fd(": No such file or directory ", 2);
	}
	if (b == 3)
	{
		ft_putstr_fd(a, 2);
		ft_putendl_fd(": command not found", 2);
	}
}

static char	**get_path(char **env)
{
	char	**path;
	int		i;

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

static char	*ret_path(char **env, char *cmd)
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
		if (access(tpath, X_OK) == 0 && access(tpath, F_OK) == 0)
			return (tpath);
		else if (access(tpath, X_OK) != 0 && access(tpath, F_OK) == 0)
		{
			free(tpath);
			ft_puterr(cmd, 1);
		}
		free(tpath);
		path++;
	}
	ft_puterr(cmd, 3);
	exit(127);
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
			if (access(cmds[0], F_OK) == 0)
			{
				ft_puterr(cmds[0], 1);
				free(cmds);
			}
			else
				ft_puterr(cmds[0], 2);
			free(path);
			free(cmds);
			exit (127);
		}
	}
	else
		path = ret_path(env, cmds[0]);
	execve(path, cmds, env);
	free(cmds);
}
