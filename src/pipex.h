/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:14:49 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/02/28 13:14:53 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	int		pipefd[2];
	int		file1_fd;
	int		file2_fd;
	int		pid1;
	int		pid2;
	char	**args1;
	char	**args2;
}t_pipex;

typedef struct s_split
{
	int		i;
	int		wordcount;
	int		wordlen;
	char	**array;
}t_split;

char	**pipex_split(char const *s, char c);
void	free_array(char **arr);
int		close_free_wait(t_pipex *var);

#endif
