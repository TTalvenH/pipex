/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:14:39 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/02/28 13:14:41 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "pipex.h"
#include "../libft/libft.h"

char	*check_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (paths[i] != '\0')
	{
		cmd_path = ft_strjoin_slash(paths[i++], cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			free_array(paths);
			return (cmd_path);
		}
		free(cmd_path);
	}	
	free_array(paths);
	return (NULL);
}

char	*find_cmd_path(char *cmd)
{
	extern char	**environ;
	int			i;
	char		**paths;
	char		*cmd_path;

	i = 0;
	while (ft_strncmp(environ[i], "PATH", 4) != 0 && environ[i] != NULL)
		i++;
	paths = ft_split(environ[i] + 5, ':');
	cmd_path = check_paths(paths, cmd);
	return (cmd_path);
}

int	child_execve(char **arg, int input_fd, int output_fd, int close_fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid == 0 && (input_fd >= 0 && output_fd >= 0))
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
		close(input_fd);
		close(close_fd);
		execve(find_cmd_path(arg[0]), arg, 0);
		exit(-1);
	}
	return (pid);
}

int	init_var(t_pipex *var, char **argv)
{
	var->args1 = pipex_split(argv[2], ' ');
	if (var->args1 == NULL)
	{
		perror("cmd1");
		return (-1);
	}
	var->args2 = pipex_split(argv[3], ' ');
	if (var->args2 == NULL)
	{
		perror("cmd2");
		if (var->args1)
			free_array(var->args1);
		return (-1);
	}
	var->file1_fd = open(argv[1], O_RDONLY);
	if (var->file1_fd < 0)
		perror(argv[1]);
	var->file2_fd = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0664);
	if (var->file2_fd < 0)
		perror(argv[4]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pipex	var;

	if (argc == 5)
	{
		if (init_var(&var, argv) < 0)
			return (-1);
		if (pipe(var.pipefd) == 0)
		{
			if (var.file1_fd >= 0)
				var.pid1 = child_execve(var.args1, var.file1_fd,
						var.pipefd[1], var.pipefd[0]);
			if (var.file2_fd >= 0)
				var.pid2 = child_execve(var.args2, var.pipefd[0],
						var.file2_fd, var.pipefd[1]);
			if (close_free_wait(&var) != 0)
				return (-1);
		}
		else
			perror("pipe");
	}
	else
		ft_printf_fd(2, "Like this: ./pipex file1 \"cmd1\" \"cmd2\" file2\n");
}
