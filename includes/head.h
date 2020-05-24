#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
# include <sys/select.h>
# include <curses.h>
# include <unistd.h>
# include <termios.h>

# define TRUE		1
# define FALSE		0

# define SNK_SNAKE	'@'
# define SNK_FOOD	'+'
# define SNK_EMPTY	' '
# define SNK_WALL	'#'

# define WIDTH		80
# define HEIGHT		25

# define SNK_ROW	0
# define SNK_COL	1

# define SNK_RIGHT	4414235
# define SNK_DOWN	4348699
# define SNK_LEFT	4479771
# define SNK_UP		4283163

# define SEED_MAX	123456789

typedef struct		s_coor
{
	int				row;
	int				col;
}					t_coor;

typedef struct		s_snake
{
	t_list			*body;
	int				len;
	
}					t_snake;

typedef struct		s_arena
{
	int				width;
	int				height;
	int				move[2];
	int				total_size;
	char			**board;
	t_snake			*snake;
	t_coor			food;

}					t_arena;

# include "auto_Snake.h"

#endif
