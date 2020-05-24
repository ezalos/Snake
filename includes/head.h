#ifndef HEAD_H
# define HEAD_H

# include "libft.h"

# define TRUE		1
# define FALSE		0

# define SNK_SNAKE	'@'
# define SNK_FOOD	'+'
# define SNK_EMPTY	' '
# define SNK_WALL	'#'

# define WIDTH		80
# define HEIGHT		25
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
	int				total_size;
	char			**board;
	t_snake			*snake;
	t_coor			food;

}					t_arena;

# include "auto_Snake.h"

#endif
