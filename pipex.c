/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:36 by yalp              #+#    #+#             */
/*   Updated: 2024/12/18 19:33:07 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void childp(char **argv, int fd[2], char **env)
{
	int ffd;

	ffd = open(argv[1], O_RDONLY);
	if (ffd == -1)
	{
		ft_putstr_fd(argv[1], 1);
		ft_putendl_fd(" no such file or directory", 1);
	}
	close(fd[0]);
	dup2(ffd, STDIN_FILENO);
	close(ffd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_pipex_run(argv[2], env);
}

void parentp(char **argv, int fd[2], char **env)
{	
	int ffd;
	ffd = open(argv[4], O_CREAT | O_RDWR);
	if (ffd == -1)
	{
		ft_putstr_fd(argv[4], 1);
		ft_putendl_fd(" no such file or directory", 1);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(ffd, STDOUT_FILENO);
	close(ffd);
	ft_pipex_run(argv[3], env);
	
}

int main(int argc, char **argv, char **env)
{
	int f;
	int fd[2];


	if (argc == 5)
	{
		pipe(fd);
		f = fork();
		if (f == 0)
		{
			childp(argv, fd, env);
		}
		else
		{
			waitpid(f,NULL,0);
			parentp(argv, fd, env);
			
		}
	}
	else
	{
		ft_putendl_fd("BAD ARGUMENTS!!\nEX : ./pipex file1 cmd1 cmd2 file2", 2);
	}
}
