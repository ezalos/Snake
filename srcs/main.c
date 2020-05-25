#include "head.h"

void		play_game(t_arena *arena)
{
	_C_CLEAR_SCREEN;
	snk_print(arena);
	while (arena->game_over == FALSE)
	{
		get_input(arena);
		move_snake(arena);
	}
	ft_printf("sorry you lost baby....\n");
}

int 		main(int ac, char **av)
{
	t_arena		arena;
	
	(void)ac;
	(void)av;
	init_board(&arena);
	init_snake(&arena);
	play_game(&arena);
	return (0);
}
