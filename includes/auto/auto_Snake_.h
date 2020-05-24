/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_Snake_.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 20:05:45 by ezalos            #+#    #+#             */
/*   Updated: 2020/05/24 20:05:45 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_SNAKE__H
# define AUTO_SNAKE__H

void		snk_print_pxl(int type);
void		snk_print(t_arena* arena);
int main(int ac, char **av);
void		create_random(t_arena *arena, int *row, int *col);
int		check_empty(t_arena *arena, int *row, int *col);
void		fill_random(t_arena *arena, int *row, int *col, char type);
void		init_snake(t_arena *arena);
void		init_board(t_arena *arena);
void		fast_terminal(float time, int size, int on_off);
int 		get_input(t_arena *arena);

#endif
