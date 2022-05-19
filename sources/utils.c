/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:11:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/19 21:25:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	error(char *message, int code)
{
	if (!message)
		perror("Error");
	else
		ft_printf("Error: %s\n", message);
	exit(code);
}

void	free_stuff(char	**free_this, char *free_that)
{
	int	i;

	i = 0;
	free(free_that);
	while (free_this[i])
	{
		free(free_this[i]);
		i++;
	}
	if (free_this)
		free(free_this);
}

void	is_cmd_spaces(char *cmd_arg, char *cmd_err)
{
	int		i;

	i = 0;
	while (cmd_arg[i] == ' ' || cmd_arg[i] == '\t'
		|| cmd_arg[i] == '\r' || cmd_arg[i] == '\n'
		|| cmd_arg[i] == '\v' || cmd_arg[i] == '\f')
		i++;
	if (!cmd_arg[i])
		error(cmd_err, 127);
}
