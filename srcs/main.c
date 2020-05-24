#include "head.h"

int main(int ac, char **av)
{
	t_arena		arena;
	
	init_board(&arena);
	(void)ac;
	(void)av;
	while (1)
	{
		get_input(&arena);
		((t_coor*)arena.snake->body->content)->row += arena.move[SNK_ROW];
		((t_coor*)arena.snake->body->content)->col += arena.move[SNK_COL];
		snk_print(&arena);
	}
	return (0);
}
