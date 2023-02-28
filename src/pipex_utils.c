/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:08 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/02/28 13:15:09 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"
#include "../libft/libft.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (*arr != NULL)
	{
		free(*arr++);
		i++;
	}
	free(arr - i);
}

int	close_free_wait(t_pipex *var)
{
	int	wstatus;
	int	status;

	status = 0;
	close(var->file1_fd);
	close(var->file2_fd);
	close(var->pipefd[0]);
	close(var->pipefd[1]);
	waitpid(var->pid1, &wstatus, WUNTRACED | WCONTINUED);
	if (wstatus)
	{
		ft_printf_fd(STDERR_FILENO, "Couldn't execute '%s'\n", var->args1[0]);
		status = -1;
	}
	waitpid(var->pid2, &wstatus, WUNTRACED | WCONTINUED);
	if (wstatus)
	{
		ft_printf_fd(STDERR_FILENO, "Couldn't execute '%s'\n", var->args2[0]);
		status = -1;
	}
	free_array(var->args1);
	free_array(var->args2);
	return (status);
}
