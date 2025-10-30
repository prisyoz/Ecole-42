/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:59:52 by pang              #+#    #+#             */
/*   Updated: 2025/09/27 15:03:46 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# include "../libft/libft01/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	**envp;
}	t_pipex;

void	process_cmd1(t_pipex *pipex, char *av, char **envp);
void	process_cmd2(t_pipex *pipex, char *av, char **envp);
void	close_pipes(t_pipex *pipex);
void	init_pipes(t_pipex *pipex, char **argv);
void	fork_processes(t_pipex *pipex, char **argv, char **envp);
void	exit_error(char *msg, t_pipex *pipex);
void	free_arr(char **arr);
void	free_all(char **arr, int count);
void	exit_with_error(char *cmd, char *msg, int code);
int		infile_check(const char *filename);
int		outfile_check(const char *filename);
int		skip_quote(char *str, int count);
int		words_count(char *str);
int		is_whitespace(char c);
int		skip_whitespace(char *str, int count);
int		ft_printf(const char *format, ...);
char	**env_path(char **envp);
char	*single_path(char *cmd, char **envp);
char	*path_access(char *cmd);
char	**check_av_access(char **av, char **envp);
char	**execute_check(char *cmd, char **envp);
char	*extract_quoted_word(char *str, int *count);
char	*extract_unquoted_word(char *str, int *count);
char	*extract_word(char *str, int *count);
char	**parse_command(char *str);
char	*ft_3join(char const *s1, char const *s2, char const *s3);
char	*malloc_word(char *start, int len);

/* void	test_parsing(void);
void	debug_parse_result(char **result); */
#endif