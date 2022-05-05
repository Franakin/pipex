/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:54:28 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/20 14:17:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*get_path(char *cmd_arg, char **envp)
{
	char	*cmd;
	char	*cmd_err;
	char	*tmp;
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = pipex_split(*envp, ':');
	cmd = ft_strdup(cmd_arg);
	cmd_err = ft_strjoin("Command not found: ", cmd_arg);
	if (!paths || !cmd)
		error(NULL, 1);
	while (access(cmd, X_OK) == -1 && *paths)
	{
		free(cmd);
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, cmd_arg);
		if (!tmp || ! cmd)
			error(NULL, 1);
		paths++;
	}
	if (!*paths)
		error(cmd_err, 127);
	return (cmd);
}

void	child1(char **argv, char **envp, t_pipex *pipex)
{
	char	**cmd_arg;
	char	*cmd;

	pipex->infd = open(argv[1], O_RDONLY);
	cmd_arg = pipex_split(argv[2], ' ');
	if (pipex->infd < 0 || !cmd_arg)
		error(NULL, 1);
	cmd = get_path(*cmd_arg, envp);
	if (dup2(pipex->infd, 0) == -1)
		error(NULL, 1);
	if (close(pipex->tube[0]) == -1)
		error(NULL, 1);
	if (dup2(pipex->tube[1], 1) == -1)
		error(NULL, 1);
	execve(cmd, cmd_arg, envp);
}

void	child2(char **argv, char **envp, t_pipex *pipex)
{
	char	**cmd_arg;
	char	*cmd;

	pipex->outfd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmd_arg = pipex_split(argv[3], ' ');
	if (pipex->outfd < 0 || !cmd_arg)
		error(NULL, 1);
	cmd = get_path(*cmd_arg, envp);
	if (dup2(pipex->outfd, 1) == -1)
		error(NULL, 1);
	if (close(pipex->tube[1]) == -1)
		error(NULL, 1);
	if (dup2(pipex->tube[0], 0) == -1)
		error(NULL, 1);
	execve(cmd, cmd_arg, envp);
}
