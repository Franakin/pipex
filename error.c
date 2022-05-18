/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:11:17 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/18 13:49:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
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
