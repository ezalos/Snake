#include "head.h"

int main(int ac, char **av)
{
	t_arena		arena;
	
	init_board(&arena);
	if (ac > 1)
		ft_printf("%s\n", av[1]);
	return (0);
}
