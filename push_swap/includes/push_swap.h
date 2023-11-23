/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:45:22 by mho               #+#    #+#             */
/*   Updated: 2023/11/23 08:06:17 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum		e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
};

typedef struct s_pushswap
{
	t_stack	*a;
	t_stack	*b;
	t_list	*op;

}			t_ps;

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		head;
	int		tail;
}			t_stack;

typedef struct s_chunk
{
	enum e_loc	loc;
	int		index; //dk if need yet
	int		size;

}			t_chunk;

typedef struct s_split
{
	t_chunk	*min;
	t_chunk	*mid;
	t_chunk	*max;
}			t_split;

#endif
