#ifndef PIPEX_H
# define PIPEX_H
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"



void	ft_pipex_run(char *cmd, char **env);
#endif