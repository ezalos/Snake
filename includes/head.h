#ifndef HEAD_H
# define HEAD_H

# include "libft.h"

# define SNK_SNAKE	'@'
# define SNK_FOOD	'+'
# define SNK_EMPTY	' '
# define SNK_WALL	'#'

# define WIDTH		80
# define HEIGHT		25


typedef struct		s_snake
{
	int				width;
	int				height;
	int				total_size;
	char			**board;

}					t_snake;

# include "auto_Snake.h"

#endif
