/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:36 by yalp              #+#    #+#             */
/*   Updated: 2024/12/16 16:29:08 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void childp(char **argv, int fd[2], char *env)
{
	int ffd;

	ffd = open(argv[1], O_RDONLY);
	if (ffd == -1)
	{
		ft_putstr_fd(argv[1], 1);
		ft_putendl_fd(" no such file or directory", 1);
	}
	close(fd[1]);
	dup2(ffd, STDIN_FILENO);
	

	
}

void parentp(char **argv, int fd[2], char *env)
{	
	int ffd;
	ffd = open(argv[4], O_CREAT | O_RDWR);
	if (ffd == -1)
	{
		ft_putstr_fd(argv[4], 1);
		ft_putendl_fd(" no such file or directory", 1);
	}
	close(fd[0]);
	dup2(ffd, STDOUT_FILENO);
	
}

int main(int argc, char **argv, char *env)
{
	int f;
	int fd[2];

	pipe(fd);
	f = fork();
	if (argc == 5)
	{
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
