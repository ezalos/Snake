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
	if (type == SNK_FOOD)
	{
		arena->food.row = *row;
		arena->food.col = *col;
	}
}

t_list			*ft_lstcut(t_list **alst, int indx)
{
	t_list	*search;
	t_list	*to_cut;
	int		i;

	i = 0;
	search = *alst;
	to_cut = *alst;
	if (indx == 0)
	{
		*alst = search->next;
		to_cut->next = NULL;
		return (to_cut);
	}
	while (search != NULL 
		&& search->next != NULL 
		&& search->next->next != NULL 
		&& (i + 1 < indx|| indx == -1))
	{
		search = search->next;
		i++;
	}
	to_cut = search->next;
	search->next = to_cut->next;
	to_cut->next = NULL;
	return (to_cut);
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

void			get_bigger(t_arena *arena)
{
	t_list	*new;
	t_coor	*coor;	

	coor = ft_memalloc(sizeof(t_coor));
	coor->row = arena->food.row;
	coor->col = arena->food.col;
	new = ft_lstnew(coor, sizeof(t_coor*));
	ft_lstadd_start(&(arena->snake->body), new);
	fill_random(arena, &arena->food.row, &arena->food.col, SNK_FOOD);
}

void			change_type(t_arena *arena, t_list *change, char type)
{
	int		row;
	int		col;

	row = ((t_coor*)change->content)->row;
	col = ((t_coor*)change->content)->col;
	if (type == SNK_SNAKE && arena->board[row][col] == SNK_FOOD)
		get_bigger(arena);
	arena->board[row][col] = type;
}

void			move_head(t_coor *new, t_coor *old, t_arena *arena)
{
	new->row = old->row + arena->move[SNK_ROW];
	if (new->row < 0)
		new->row = arena->height - 1;
	else if (new->row >= arena->height)
		new->row = 0;
	new->col = old->col + arena->move[SNK_COL];
	if (new->col < 0)
		new->col = arena->width - 1;
	else if (new->col >= arena->width)
		new->col = 0;
}

void			move_snake(t_arena *arena)
{
	t_list		*to_move;

	if (arena->snake->len > 1)
	{
		to_move = ft_lstcut(&(arena->snake->body), -1);
		change_type(arena, to_move, SNK_EMPTY);
		move_head(to_move->content, arena->snake->body->content, arena);
		ft_lstadd_start(&(arena->snake->body), to_move);
		change_type(arena, to_move, SNK_SNAKE);
	}
	else
	{
		change_type(arena, arena->snake->body, SNK_EMPTY);
		move_head(arena->snake->body->content, arena->snake->body->content, arena);
		change_type(arena, arena->snake->body, SNK_SNAKE);
	}	
}

void			play_game(t_arena *arena)
{
	int		turn;

	turn = 0;
	while (turn < 100)
	{
		get_input(arena);
		move_snake(arena);
		snk_print(arena);
		turn++;
	}
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
	play_game(arena);
}
