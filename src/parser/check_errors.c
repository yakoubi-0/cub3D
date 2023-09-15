/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:24 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/09/14 15:08:41 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_errors(t_data_maps *data, t_list *list)
{
	if (check_errors_textures(data->textures) == FALSE)
		return (FALSE);
	if (check_errors_colors(data) == FALSE)
		return (FALSE);
	if (check_errors_map(data, list) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_errors_textures(char **textures)
{
	int i;
	int	count;
	char **tmp;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		if(textures[i])
			count++;
	}
	if (count != 4)
		return (FALSE);
	i = -1;
	while (++i < 4)
	{
		tmp = ft_split(textures[i], ' ');
		if (!tmp[1] || (tmp[1] && tmp[2]))
			return (FALSE);
		free(tmp);
	}
	return (TRUE);
}

int	check_errors_colors(t_data_maps *data)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (data->F[i] < 0 || data->F[i] > 255)
			return (FALSE);
		if (data->C[i] < 0 || data->C[i] > 255)
			return (FALSE);
	}
	return (TRUE);
}

int check_errors_map(t_data_maps *data, t_list *list)
{
	(void) list;
	t_corMap *posStart;

	if (check_intruderInMap(data->map) == FALSE)
		return (FALSE);
	posStart = init_corMap(data->map);
	if (posStart == FALSE)
		return (FALSE);
	if (loopForMap(data->map, posStart) == FALSE)
		return (FALSE);
	return (TRUE);
}

int loopForMap(char **map, t_corMap *pos)
{
	t_listMap *cur;
	t_listMap *first;
	int	var;

	var = 0;
	first = newlist(pos->x, pos->y);
	cur = first;
	while (cur)
	{/*
		if (cur->x != first->x && cur->y != cur->y)
		{
			if (map[cur->y][cur->x] == '0')
			{
				var = -1;
				if (lstadd(cur, newlist(cur->x + 1, cur->y), map, var) == FALSE)
					return (FALSE);
				if (lstadd(cur, newlist(cur->x - 1, cur->y), map, var) == FALSE)
					return (FALSE);
				if (lstadd(cur, newlist(cur->x, cur->y + 1), map, var) == FALSE)
					return (FALSE);
				if (lstadd(cur, newlist(cur->x, cur->y - 1), map, var) == FALSE)
					return (FALSE);
			}
			else
			{
				if (map[cur->y][cur->x + 1] == '1'
					|| map[cur->y][cur->x + 1] == '0')
					lstadd(cur, newlist(cur->x + 1, cur->y), map, var);
				if (map[cur->y][cur->x - 1] == '1'
					|| map[cur->y][cur->x - 1] == '0')
					lstadd(cur, newlist(cur->x - 1, cur->y), map,var);
				if (map[cur->y + 1][cur->x] == '1'
					|| map[cur->y + 1][cur->x] == '0');
					lstadd(cur, newlist(cur->x, cur->y + 1), map, var);
				if (map[cur->y - 1][cur->x] == '1'
					|| map[cur->y - 1][cur->x] == '0')
					lstadd(cur, newlist(cur->x, cur->y - 1), map, var);
			}
		}
		else
		{*/
			if (map[cur->y][cur->x + 1] == '1'
				|| map[cur->y][cur->x + 1] == '0')
				lstadd(cur, newlist(cur->x + 1, cur->y), map, var);
			if (map[cur->y][cur->x - 1] == '1'
				|| map[cur->y][cur->x - 1] == '0')
				lstadd(cur, newlist(cur->x - 1, cur->y), map, var);
			if (map[cur->y + 1][cur->x] == '1'
				|| map[cur->y + 1][cur->x] == '0');
				lstadd(cur, newlist(cur->x, cur->y + 1), map, var);
			if (map[cur->y - 1][cur->x] == '1'
				|| map[cur->y - 1][cur->x] == '0')
				lstadd(cur, newlist(cur->x, cur->y - 1), map, var);
		//}
		cur = cur->next;
	}
	return (TRUE);
}	
