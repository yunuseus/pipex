/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:36 by yalp              #+#    #+#             */
/*   Updated: 2024/12/23 17:45:07 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	childp(char **argv, int fd[2], char **env)
{
	int	ffd;

	ffd = open(argv[1], O_RDONLY);
	if (ffd == -1)
	{
		if (access(argv[1], R_OK) == -1 && access(argv[1], F_OK) != -1)
		{
			ft_putstr_fd(argv[1], 2);
			ft_putendl_fd(": Permission denied ", 2);
			exit (1);
		}
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit (1);
	}
	close(fd[0]);
	dup2(ffd, STDIN_FILENO);
	close(ffd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_pipex_run(argv[2], env);
}

static void	parentp(char **argv, int fd[2], char **env)
{	
	int	ffd;

	ffd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ffd == -1)
	{
		if (access(argv[4], W_OK) == -1)
		{
			ft_putstr_fd(argv[4], 2);
			ft_putendl_fd(": Permission denied ", 2);
			exit (1);
		}
		ft_putstr_fd(argv[4], 2);
		ft_putendl_fd(" No such file or directory", 2);
		exit (1);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(ffd, STDOUT_FILENO);
	close(ffd);
	close(fd[1]);
	ft_pipex_run(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	f;
	int	fd[2];

	if (argc == 5)
	{
		pipe(fd);
		f = fork();
		if (f == 0)
			childp(argv, fd, env);
		waitpid(f, NULL, 0);
		parentp(argv, fd, env);
	}
	else
		ft_putendl_fd("BAD ARGUMENTS!!\nEX : ./pipex file1 cmd1 cmd2 file2", 2);
	return (1);
}
