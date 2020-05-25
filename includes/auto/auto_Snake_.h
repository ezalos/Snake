/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_Snake_.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:17:42 by deyaberge         #+#    #+#             */
/*   Updated: 2020/05/25 00:17:42 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_SNAKE__H
# define AUTO_SNAKE__H

void		snk_print_pxl(int type);
void		snk_print(t_arena* arena);
void		create_random(t_arena *arena, int *row, int *col);
int		check_empty(t_arena *arena, int *row, int *col);
void		fill_random(t_arena *arena, int *row, int *col, char type);
t_list		*ft_lstcut(t_list **alst, int indx);
void		init_snake(t_arena *arena);
void		change_type(t_arena *arena, t_list *change, char type);
void		get_bigger(t_arena *arena, t_coor add_spot);
char		check_move(t_coor *new, t_coor *old, t_arena *arena);
void		move_snake(t_arena *arena);
void		play_game(t_arena *arena);
void		init_board(t_arena *arena);
void		fast_terminal(float time, int size, int on_off);
int 		get_input(t_arena *arena);
int main(int ac, char **av);

#endif
