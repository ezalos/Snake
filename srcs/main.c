#include "head.h"

int main(int ac, char **av)
{
	if (ac > 1)
		printf("%s %jd\n", av[1], ft_rand(10, 10));
	return (0);
}
