#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"


void	free_array(char **arr)
{
	int i;

	i = 0;
	while(*arr != NULL)
	{
		free(*arr++);
		i++;
	}
	free(arr - i);
}

char	*check_paths(char **paths, char *cmd)
{
	int i;
	char *cmd_path;

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
	extern char **environ;
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	while (ft_strncmp(environ[i], "PATH", 4) != 0 && environ[i] != NULL)
		i++;
	paths = ft_split(environ[i] + 5, ':');
	cmd_path = check_paths(paths, cmd);
	free(cmd);
	return (cmd_path);
}

int	child_execve(char **arg, int input_fd, int output_fd, int close_fd)
{
	int pid;

	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if(pid == 0 && (input_fd >= 0 && output_fd >= 0))
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
		close(input_fd);
		close(close_fd);
		execve(find_cmd_path(arg[0]), arg, 0);
		ft_printf_fd(STDERR_FILENO, "Error: could not execute '%s'\n", arg[0]);
	}
	return (pid);
}

char	**split_args(char *arg)
{
	char	**args;

	args = pipex_split(arg, ' ');
	while(*args != NULL)
		ft_printf("%s\n", *args++);
	return (args);
}

int main(int argc, char **argv)
{
	int	pipefd[2];
	int	file1_fd;
	int file2_fd;
	int	pid1;
	int pid2;
	char	**args1;
	char	**args2;


	if (argc == 5)
	{
		args1 = pipex_split(argv[2], ' ');
		args2 = pipex_split(argv[3], ' ');
		file1_fd = open(argv[1], O_RDONLY);
		if (file1_fd < 0)
			perror("Error");
		file2_fd = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0664);
		if (file2_fd < 0)
			perror("Error");
		if(pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(0);
		}
		if (file1_fd >= 0)
		{
			pid1 = child_execve(args1, file1_fd, pipefd[1], pipefd[0]);
		}
		pid2 = child_execve(args2, pipefd[0], file2_fd, pipefd[1]);
		
		close(file1_fd);
		close(file2_fd);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		split_args(argv[1]);
	return 0;
}