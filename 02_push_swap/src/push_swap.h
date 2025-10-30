/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:46:33 by pang              #+#    #+#             */
/*   Updated: 2025/09/12 17:02:52 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				sorted_index;
	int				ori_index;
	int				keep;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				dir_a;
	int				dir_b;
	struct s_node	*next;
}	t_node;

typedef struct s_struct
{
	char	*combined_str;
	char	**char_arr;
	int		*int_arr;
	int		*sorted_arr;
	int		arr_size;
	int		ins_count;
	int		*dp;
	int		*prev;
	int		lis_max_seq;
	int		chunk_count;
	int		*percentile;
	int		seen_node;
	int		push_node;
	int		current_size;
	int		current_chunk;
	int		size_a;
	int		size_b;
	int		lis_min_a;
	int		lis_max_a;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*best_node;
}	t_struct;

char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
long	ft_atol(const char *arr);
char	*get_next_line(int fd);

void	split_argument(int argc, char **argv, t_struct *data);
char	*argument_to_array(int argc, char **argv);
int		valid_number(char *arr);
int		check_validity(t_struct *data);
int		check_dup(char **arr);
int		data_size(t_struct *data);
int		*validate_and_convert(t_struct *data);
int		verify_stack_order(t_struct *data);

void	parse_stack_a(t_struct *data);
void	ft_lstadd_back_node(t_node **lst, t_node *new_node);
t_node	*ft_lstnew_node(int value);

// Sort basic
int		find_min_value(t_node *stack);
int		find_index(t_node *stack, int value);
void	push_smallest_to_b(t_struct *data);
void	sort_two(t_struct *data);
void	sort_three(t_struct *data);
void	sort_five(t_struct *data);

// Array sort
void	index_stack(t_struct *data);
void	sorted_arr(t_struct *data);
void	bubble_sort(t_struct *data);
void	sort_data(t_struct *data);
int		find_arr_index(int *arr, int value, int arr_size);

// Algo sort
void	lis_init(t_struct *data);
void	set_longest_seq(t_struct *data);
void	mark_keep(t_struct *data, int index);
void	stack_a_keeps(t_struct *data, int index);
void	stack_a_lis(t_struct *data);
void	find_lis_minmax_a(t_struct *data);

void	total_chunks(t_struct *data);
void	percentile_boundaries(t_struct *data);
void	push_to_b(t_struct *data);
void	update_chunk(t_struct *data);
int		chunk_target(t_struct *data, int index, int chunk);
int		push_chunk_node(t_struct *data, t_node *curr, int chunk);

void	moves_rotate_a(t_struct *data, t_node *target_node);
void	moves_to_rotate_b(t_struct *data, t_node *target_node);
void	total_cost_to_push(t_node *curr_b);
void	check_ab_cost(t_struct *data);
void	data_sort(t_struct *data);

t_node	*find_best_move(t_struct *data);
void	execute_moves_a(t_node *best_node, t_struct *data);
void	execute_moves_b(t_node *best_node, t_struct *data);
void	execute_moves_ab(t_node *best_node, t_struct *data);
void	moving_sort(t_struct *data);
void	final_sort_a(t_struct *data);
void	sort_lis_stack_a(t_struct *data);
int		find_sorted_pos(t_node *stack, int target_sorted_index);
int		find_safe_insertion_position(t_struct *data, int sorted_index);
int		outside_bound_position(t_struct *data);

// Free
void	free_array(char **arr);
void	free_exit(t_struct *data);
void	free_errorexit(t_struct *data);
void	free_stack(t_node *stack);

// Print instructions
void	rotate_a(t_struct *data);
void	rotate_b(t_struct *data);
void	rotate_ab(t_struct *data);
void	push_a(t_struct *data);
void	push_b(t_struct *data);
void	swap_a(t_struct *data);
void	swap_b(t_struct *data);
void	swap_ab(t_struct *data);
void	revrotate_a(t_struct *data);
void	revrotate_b(t_struct *data);
void	revrotate_ab(t_struct *data);

// Instructions
void	rotate_a_clean(t_struct *data);
void	rotate_b_clean(t_struct *data);
void	swap_a_clean(t_struct *data);
void	swap_b_clean(t_struct *data);
void	revrotate_a_clean(t_struct *data);
void	revrotate_b_clean(t_struct *data);

#endif