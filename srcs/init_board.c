#include "head.h"

t_snake			init_board(void)
{
	t_snake		snake;
	int			raw;
	int			i;

	snake.width = WIDTH;
	snake.height = HEIGHT;
	snake.total_size = WIDTH * HEIGHT;
	snake.board = ft_memalloc(sizeof(char*) * HEIGHT);
	raw = 0;
	while (raw < HEIGHT)
	{
		snake.board[raw] = ft_memalloc(sizeof(char) * WIDTH);
		raw++;
	}
	i = 0;	
	return (snake);	
}
