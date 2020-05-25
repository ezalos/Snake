/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:15:02 by ezalos            #+#    #+#             */
/*   Updated: 2020/05/25 10:54:30 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
# define SNK_RIGHT						4414235
# define SNK_DOWN						4348699
# define SNK_LEFT						4479771
# define SNK_UP							4283163
#include <sys/select.h>
#include <curses.h>
#include <unistd.h>
#include <termios.h>

void		fast_terminal(float time, int size, int on_off)
{
	static struct termios	old = {0};

	if (on_off)
	{
		if (tcgetattr(0, &old) < 0)
			perror("tcsetattr()");
		old.c_lflag &= ~ICANON;
		old.c_lflag &= ~ECHO;
		old.c_cc[VMIN] = size;
		old.c_cc[VTIME] = time;
		if (tcsetattr(0, TCSANOW, &old) < 0)
			perror("tcsetattr ICANON");
	}
	else
	{
		old.c_lflag |= ICANON;
		old.c_lflag |= ECHO;
		if (tcsetattr(0, TCSADRAIN, &old) < 0)
			perror("tcsetattr ~ICANON");
	}
}


int 	get_input(t_arena *arena)
{
	int	input;

	fast_terminal(5, 0, 1);
	input = 0;
	read(0, (char*)&input, 3);
	fast_terminal(0.3, sizeof(input), 0);
	if ((input == SNK_UP
	||  input == 'w') && arena->move[SNK_ROW] == 0)
	{
		arena->move[SNK_ROW] = -1;
		arena->move[SNK_COL] = 0;
	}
	else if ((input == SNK_DOWN
		 ||  input == 's') && arena->move[SNK_ROW] == 0)
	{
		arena->move[SNK_ROW] = 1;
		arena->move[SNK_COL] = 0;
	}
	else if ((input == SNK_LEFT
		 ||  input == 'a') && arena->move[SNK_COL] == 0)
	{
		arena->move[SNK_ROW] = 0;
		arena->move[SNK_COL] = -1;
	}
	else if ((input == SNK_RIGHT
		 ||  input == 'd') && arena->move[SNK_COL] == 0)
	{
		arena->move[SNK_ROW] = 0;
		arena->move[SNK_COL] = 1;
	}
	return (0);
}










