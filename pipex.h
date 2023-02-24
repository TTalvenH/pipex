#ifndef PIPEX_H
 #define PIPEX_H

typedef struct s_pipex
{
	int	pipefd[2];
	int	file1_fd;
	int file2_fd;
	int	file1_pid;
	int file2_pid;
}t_pipex;

char	**pipex_split(char const *s, char c);
#endif	