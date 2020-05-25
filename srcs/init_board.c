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
		{
			arena->board[*row][*col] = type;
			snk_update_pxl(*row, *col, type);
		}
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
	if (search->next == NULL
		&& indx == -1)
		return (search);
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

void			change_type(t_arena *arena, t_list *change, char type)
{
	int		row;
	int		col;

	row = ((t_coor*)change->content)->row;
	col = ((t_coor*)change->content)->col;
	arena->board[row][col] = type;
	snk_update_pxl(row, col, type);
}

void			get_bigger(t_arena *arena, t_coor add_spot)
{
	t_list	*new;
	t_coor	*coor;	

	coor = ft_memalloc(sizeof(t_coor));
	coor->row = add_spot.row;
	coor->col = add_spot.col;
	new = ft_lstnew(coor, sizeof(t_coor*));
	ft_lstadd_start(&(arena->snake->body), new);
	change_type(arena, new, SNK_SNAKE);
	fill_random(arena, &arena->food.row, &arena->food.col, SNK_FOOD);
	arena->snake->len += 1;
}

char		check_move(t_coor *new, t_coor *old, t_arena *arena)
{
	new->row = old->row + arena->move[SNK_ROW];
	new->col = old->col + arena->move[SNK_COL];
	if (new->row < 0)
		new->row = arena->height - 1;
	else if (new->row >= arena->height)
		new->row = 0;
	if (new->col < 0)
		new->col = arena->width - 1;
	else if (new->col >= arena->width)
		new->col = 0;
	return (arena->board[new->row][new->col]);
}

void			move_on(t_arena *arena, t_coor check_spot)
{
		t_list		*to_move;

		to_move = ft_lstcut(&(arena->snake->body), -1);
		change_type(arena, to_move, SNK_EMPTY);
		((t_coor*)to_move->content)->row = check_spot.row;
		((t_coor*)to_move->content)->col = check_spot.col;
		if (arena->snake->len > 1)
			ft_lstadd_start(&(arena->snake->body), to_move);
		change_type(arena, to_move, SNK_SNAKE);
	
}

void			move_snake(t_arena *arena)
{
	t_coor		check_spot;;
	char		spot;

	spot = check_move(&check_spot, arena->snake->body->content, arena);
	if (spot == SNK_FOOD)
		get_bigger(arena, check_spot);
	else if (spot == SNK_SNAKE)
		arena->game_over = TRUE;
	else
		move_on(arena, check_spot);
}

void			play_game(t_arena *arena)
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

void			init_board(t_arena *arena)
{
	int			row;
	int			col;

	arena->game_over = FALSE;
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
