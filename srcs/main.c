#include "head.h"

int main(int ac, char **av)
{
	init_board();
	if (ac > 1)
		ft_printf("%s\n", av[1]);
	return (0);
}
