#include "head.h"

void			create_random(t_arena *arena, int *row, int *col)
{
	*row = ft_rand(arena->height, ft_seed_time(0, SEED_MAX));
	*col = ft_rand(arena->width, ft_seed_time(0, SEED_MAX));
}

int			check_empty(t_arena *arena, int row, int col)
{
	if (arena->board[row][col] != SNK_EMPTY)
		return (FALSE);
	return (TRUE);
}

void			fill_random(t_arena *arena, char type)
{
		int row;
		int col;

		create_random(arena, &row, &col);
		if (check_empty(arena, row, col) == FALSE)
			while (check_empty(arena, row, col) == FALSE)
				create_random(arena, &row, &col);
		else
			arena->board[row][col] = type;
}

void			init_board(t_arena *arena)
{
	int			row;
	int			col;

	arena->width = WIDTH;
	arena->height = HEIGHT;
	arena->total_size = arena->width * arena->height;
	arena->board = ft_memalloc(sizeof(char*) * arena->height);
	row = 0;
	while (row < HEIGHT)
	{
		arena->board[row] = ft_memalloc(sizeof(char) * arena->width);
		col = 0;
		while (col < WIDTH)
		{
			arena->board[row][col] = SNK_EMPTY;
			col++;
		}
		row++;
	}
	fill_random(arena, SNK_SNAKE);
	fill_random(arena, SNK_FOOD);
	snk_print(arena);
}
