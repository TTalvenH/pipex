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
#include <sys/wait.h>

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

char	**error_free(char **array, int size)
{	
	size--;
	while (size > -1)
		free(array[size--]);
	free(array);
	return (NULL);
}

int	close_free_wait(t_pipex *var)
{
	int	wstatus;

	wstatus = 0;
	close(var->file1_fd);
	close(var->file2_fd);
	close(var->pipefd[0]);
	close(var->pipefd[1]);
	if (var->pid1)
		waitpid(var->pid1, &wstatus, 0);
	if (var->pid2)
		waitpid(var->pid2, &wstatus, 0);
	if (var->args1)
		free_array(var->args1);
	if (var->args2)
		free_array(var->args2);
	return (wstatus);
}
