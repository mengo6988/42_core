/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:45:22 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 09:01:48 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum				e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
};

enum				e_op
{
	e_rb,
	e_ra,
	e_rr,
	e_rra,
	e_rrb,
	e_rrr,
	e_pa,
	e_pb,
	e_sa,
	e_sb,
	e_ss
};

typedef struct s_stack
{
	int				*arr;
	int				size;
	int				head;
	int				tail;
}					t_stack;

typedef struct s_chunk
{
	enum e_loc		loc;
	int				size;

}					t_chunk;

typedef struct s_split
{
	t_chunk			min;
	t_chunk			mid;
	t_chunk			max;
}					t_split;

typedef struct s_oplst
{
	struct s_oplst	*next;
	enum e_op		op;
}					t_ol;

typedef struct s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_ol			*op;

}					t_ps;

// chunk_util
int					chunk_max_value(t_ps *data, t_chunk *chunk);
int					get_index(t_ps *data, t_chunk *chunk);
int					chunk_value(t_ps *data, t_chunk *chunk);

// data_io
int					str_isvalid(char *str);
void				print_op(t_ol *op);
void				init_ol(char **arr);
void				output_check(t_ol *op);
char				**parse_args(int ac, char **av);

// move
int					move_elements(t_ps *data, enum e_loc from, enum e_loc to);
void				move_from_top_a(t_ps *data, enum e_loc to);
void				move_from_top_b(t_ps *data, enum e_loc to);
void				move_from_bot_b(t_ps *data, enum e_loc to);
void				move_from_bot_a(t_ps *data, enum e_loc to);

// ol utils
t_ol				*op_new(enum e_op op);
t_ol				*op_lstlast(t_ol *lst);
void				op_lstadd_back(t_ol **lst, t_ol *new);

// print
void				combine_ab(t_ol *op, enum e_op o);
void				delete_two(t_ol *op);
void				three_to_two(t_ol *op, enum e_op o);

// push
void				push_stack(t_stack *dest, t_stack *src);
void				pa(t_ps *data);
void				pb(t_ps *data);

// r
void				reverse_rotate(t_stack *stack);
void				rra(t_ps *data);
void				rrb(t_ps *data);

// r
void				rotate(t_stack *stack);
void				ra(t_ps *data);
void				rb(t_ps *data);

// simple sort
void				simple_sort_two(t_ps *data);
void				simple_sort_three(t_ps *data);
void				simple_sort_five(t_ps *data);

// small arr op
void				sort_one(t_ps *data, t_chunk *chunk);
void				sort_two(t_ps *data, t_chunk *chunk);

// sort 3 op
void				sort_three(t_ps *data, t_chunk *chunk);
void				sort_three_top_a(t_ps *data, int max);
void				sort_three_top_b(t_ps *data, int max);
void				sort_three_bot_a(t_ps *data, int max);
void				sort_three_bot_b(t_ps *data, int max);

// sort utils
void				innit_split(t_chunk *min, t_chunk *mid, t_chunk *max);
void				set_split_target(t_chunk *chunk_to_sort, t_chunk *min,
						t_chunk *mid, t_chunk *max);
void				set_pivots(t_chunk *chunk, int *large_pivot,
						int *small_pivot, int max_val);

// sort
void				sort(t_ps *data);
void				chunk_sort(t_ps *data);
void				rec_sort(t_ps *data, t_chunk *chunk_to_sort);
void				split_chunk(t_ps *data, t_chunk *chunk_to_sort,
						t_split *split);
void				loc_opti(t_ps *data, t_chunk *to_sort);

// stack init
void				init_ps(t_ps *data);
t_stack				*init_stack(int size);
void				fill_stack(t_ps *data, int ac, char **av);
void				check_duplicates(int *numbers, int size);
void				rank_numbers(int *to_rank, int *dest, int size);

// stack utils
int					is_full(t_stack *stack);
int					i_downdown(t_stack *stack, int index);
int					i_upup(t_stack *stack, int index);
int					stack_size(t_stack *stack);

// swap
void				swap(t_stack *stack);
void				sa(t_ps *data);
void				sb(t_ps *data);

#endif
