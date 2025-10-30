/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:22:16 by pang              #+#    #+#             */
/*   Updated: 2025/09/24 19:16:40 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// av == argv[2]. envp comes from main function
void	process_cmd1(t_pipex *pipex, char *av, char **envp)
{
	int	infile_fd;

	infile_fd = pipex->infile;
	if (infile_fd == -1)
		infile_fd = open("/dev/null", O_RDONLY);
	dup2(infile_fd, 0);
	if (pipex->infile != -1)
		close(pipex->infile);
	else
		close(infile_fd);
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], 1);
	close(pipex->pipefd[1]);
	close(pipex->outfile);
	pipex->cmd1 = execute_check(av, envp);
	if (!pipex->cmd1)
		exit_with_error(av, "command not found", 127);
	execve(pipex->cmd1[0], pipex->cmd1, envp);
	free_arr(pipex->cmd1);
	if (errno == EACCES)
		exit_with_error(av, "permission denied", 126);
	else
		exit_with_error(av, "execution failed", 127);
}

// av = argv[3]. envp from main function
void	process_cmd2(t_pipex *pipex, char *av, char **envp)
{
	dup2(pipex->pipefd[0], 0);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	dup2(pipex->outfile, 1);
	close(pipex->outfile);
	if (pipex->infile != -1)
		close(pipex->infile);
	pipex->cmd2 = execute_check(av, envp);
	if (!pipex->cmd2)
		exit_with_error(av, "command not found", 127);
	execve(pipex->cmd2[0], pipex->cmd2, envp);
	free_arr(pipex->cmd2);
	if (errno == EACCES)
		exit_with_error(av, "permission denied", 126);
	else
		exit_with_error(av, "execution failed", 127);
}

void	exit_with_error(char *cmd, char *msg, int code)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(code);
}
