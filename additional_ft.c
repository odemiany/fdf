/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:18:50 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:18:53 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hex_to_int(char *line)
{
	int mult;
	int res;
	int base;
	int counter;

	res = 0;
	base = 16 * 16 * 16 * 16 * 16;
	counter = 6;
	while (counter > 0)
	{
		if (*line == 'A' || *line == 'a')
			mult = 10;
		else if (*line == 'B' || *line == 'b')
			mult = 11;
		else if (*line == 'C' || *line == 'c')
			mult = 12;
		else if (*line == 'D' || *line == 'd')
			mult = 13;
		else if (*line == 'E' || *line == 'e')
			mult = 14;
		else if (*line == 'F' || *line == 'f')
			mult = 15;
		else
			mult = *line - '0';
		res = res + base * mult;
		line++;
		base /= 16;
		counter--;
	}
	return (res);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
													c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

void	init_line_variables(t_line *line, double *current, double *next)
{
	line->x1 = (int)(current[0] * 2 + 10);
	line->y1 = (int)(current[1] * 2 + 10);
	line->x2 = (int)(next[0] * 20 + 500);
	line->y2 = (int)(next[1] * 20 + 500);
	line->deltaX = abs(line->x2 - line->x1);
	line->deltaY = abs(line->y2 - line->y1);
	line->signX = line->x1 < line->x2 ? 1 : -1;
	line->signY = line->y1 < line->y2 ? 1 : -1;
	line->error = line->deltaX - line->deltaY;
	line->color = (int)(current[3]);
	line->color2 = (int)(next[3]);
}
