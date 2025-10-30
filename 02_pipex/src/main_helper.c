/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:27:42 by pang              #+#    #+#             */
/*   Updated: 2025/09/27 15:03:24 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

int	infile_check(const char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile == -1)
	{
		perror(filename);
		return (-1);
	}
	return (infile);
}

int	outfile_check(const char *filename)
{
	int	outfile;

	outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	return (outfile);
}

void	init_pipes(t_pipex *pipex, char **argv)
{
	pipex->infile = infile_check(argv[1]);
	pipex->outfile = outfile_check(argv[4]);
	if (pipe(pipex->pipefd) == -1)
		exit_error("pipe creation error", pipex);
}

void	fork_processes(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		exit_error("fork1 failed", pipex);
	if (pipex->pid1 == 0)
		process_cmd1(pipex, argv[2], envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		exit_error("fork2 failed", pipex);
	if (pipex->pid2 == 0)
		process_cmd2(pipex, argv[3], envp);
}
