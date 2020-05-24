#include "head.h"

void			create_random(t_arena *arena, int *row, int *col)
{
	*row = ft_rand(arena->height, ft_seed_time(0, SEED_MAX));
	*col = ft_rand(arena->width, ft_seed_time(0, SEED_MAX));
}

int			check_empty(t_arena *arena, int *row, int *col)
{
	if (arena->board[*row][*col] != SNK_EMPTY)
		return (FALSE);
	return (TRUE);
}

void			fill_random(t_arena *arena, int *row, int *col, char type)
{
		create_random(arena, row, col);
		if (check_empty(arena, row, col) == FALSE)
			while (check_empty(arena, row, col) == FALSE)
				create_random(arena, row, col);
		else
			arena->board[*row][*col] = type;
}

void			init_snake(t_arena *arena)
{
	t_coor		*coor;
	int			row;
	int			col;

	fill_random(arena, &row, &col, SNK_SNAKE);
	coor = ft_memalloc(sizeof(t_coor));
	coor->row = row;
	coor->col = col;
	arena->snake = ft_memalloc(sizeof(t_snake));
	arena->snake->len = 1;
	arena->snake->body = ft_lstnew(coor, sizeof(t_coor*));
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
	init_snake(arena);
	fill_random(arena, &row, &col, SNK_FOOD);
	arena->food.row = row;
	arena->food.col = col;
	snk_print(arena);
}
