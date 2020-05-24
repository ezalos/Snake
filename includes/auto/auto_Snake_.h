/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_Snake_.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deyaberger <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:46:12 by deyaberge         #+#    #+#             */
/*   Updated: 2020/05/24 15:46:12 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_SNAKE__H
# define AUTO_SNAKE__H

void		snk_print_pxl(int type);
void		snk_print(t_arena* arena);
void		create_random(t_arena *arena, int *row, int *col);
int		check_empty(t_arena *arena, int row, int col);
void		fill_random(t_arena *arena, char type);
void		init_board(t_arena *arena);
int main(int ac, char **av);

#endif
