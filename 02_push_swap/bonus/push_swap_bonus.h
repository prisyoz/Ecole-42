/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:18:26 by pang              #+#    #+#             */
/*   Updated: 2025/09/13 23:12:33 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_bonus_node
{
	int						value;
	struct s_bonus_node		*next;
}	t_bonus_node;

typedef struct s_checker
{
	char			**char_arr;
	char			*combined_str;
	int				arr_size;
	int				*int_arr;
	t_bonus_node	*stack_a;
	t_bonus_node	*stack_b;
}	t_checker;

size_t			ft_strlen(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *str, int c, size_t n);;
int				ft_strcmp(const char *s1, const char *s2);
int				ft_printf(const char *format, ...);
long			ft_atol(const char *arr);
void			free_get_next_line(void);

void			split_argument(int argc, char **argv, t_checker *checker);
void			ft_lstadd_back_node(t_bonus_node **lst, t_bonus_node *new_node);
void			parse_stack_a(t_checker *checker);
int				count_array(char **arr);
char			*argument_to_array(int argc, char **argv);
char			*get_next_line(int fd);
t_bonus_node	*ft_lstnew_node(int value);

int				check_instructions(char *line, t_checker *checker);
void			*read_stdin(t_checker *checker);

int				valid_number(char *arr);
int				check_dup(char **arr);
int				check_validity(t_checker *data);
int				*validate_and_convert(t_checker *checker);
int				verify_stack_order(t_checker *checker);
int				stack_b_stack(t_checker *checker);

void			free_array_b(char **arr);
void			free_exit(t_checker *checker);
void			free_error_exit(t_checker *checker);
void			free_stack(t_bonus_node *stack);

// instructions
void			rotate_a_bonus(t_checker *checker);
void			rotate_b_bonus(t_checker *checker);
void			rotate_ab_bonus(t_checker *checker);
void			revrotate_a_bonus(t_checker *checker);
void			revrotate_b_bonus(t_checker *checker);
void			revrotate_ab_bonus(t_checker *checker);
void			swap_a_bonus(t_checker *checker);
void			swap_b_bonus(t_checker *checker);
void			swap_ab_bonus(t_checker *checker);
void			push_a_bonus(t_checker *checker);
void			push_b_bonus(t_checker *checker);

#endif