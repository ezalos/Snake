/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2020/05/24 14:48:23 by deyaberge        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
