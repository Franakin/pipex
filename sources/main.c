/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 18:18:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/19 21:28:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		code;

	if (argc != 5)
		error("Too few arguments", 1);
	if (pipe(pipex.tube))
		error("Piping failed", 1);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child1(argv, envp, &pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child2(argv, envp, &pipex);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	waitpid(pipex.pid1, &code, 0);
	waitpid(pipex.pid2, &code, 0);
	if (WIFEXITED(code))
		exit(WEXITSTATUS(code));
	return (1);
}
