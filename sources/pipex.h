/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 16:47:26 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/19 21:25:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	int		infd;
	int		outfd;
	int		pid1;
	int		pid2;
	int		tube[2];
}				t_pipex;

//children
void	child1(char **argv, char **envp, t_pipex *pipex);
void	child2(char **argv, char **envp, t_pipex *pipex);
//utils
void	error(char *message, int code);
void	free_stuff(char	**free_this, char *free_that);
void	is_cmd_spaces(char *cmd_arg, char *cmd_err);

#endif
