/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:27:38 by mguerra           #+#    #+#             */
/*   Updated: 2023/02/08 13:06:25 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*data(void)
{
	static t_data	data;

	if (data.setup != 1)
	{
		data.setup = 1;
		data.init = 0;
		data.filename = NULL;
		data.map = (t_map *)gc_malloc(sizeof(t_map));
		data.ray = (t_ray *)gc_malloc(sizeof(t_ray));
		data.p = (t_player *)gc_malloc(sizeof(t_player));
		data.img = (t_img *)gc_malloc(sizeof(t_img));
		data.move = (t_move *)gc_malloc(sizeof(t_move));
	}
	return (&data);
}

int get_nb_row()
{
	int len;
	char *tmp;
	int fd;

	clo_ope();
	fd = data()->fd;
	len = 0;
	tmp = "";
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		len++;
		free(tmp);
	}
	return (len);
}

int get_nb_row_splitted()
{
	printf("\n\n\n\n");
	int len;
	char *tmp;
	int fd;

	clo_ope();
	fd = data()->fd;
	len = 1;
	tmp = get_next_line(fd);
	while (tmp && (*tmp != '1' && *tmp != ' ' && *tmp != '0'))
	{
		tmp = get_next_line(fd);
	}
	printf("GETNBROWSPLITTED TMP = %s\n", tmp);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		printf("GETNBROWSPLITTED WHILETMP = %s\n", tmp);
		if (tmp == NULL)
			break;
		len++;
		free(tmp);
	}
	tmp = get_next_line(fd);

	printf("GETNBROWSPLITTED = %d\n\n\n\n", len);
	return (len);
}

int get_nb_col_splitted()
{
	int len;
	char *tmp;
	int fd;
	int temp;
	int i;

	clo_ope();
	fd = data()->fd;
	len = 0;
	tmp = "";

	tmp = get_next_line(data()->fd);
	while (tmp && (*tmp != '1' && *tmp != ' ' && *tmp != '0'))
	{
		tmp = get_next_line(data()->fd);
	}
	printf("GETNBCOL TMP = %s\n", tmp);

	while (tmp)
	{
		temp = 0;
		i = 0;
		while (tmp[i])
		{
			if (tmp[i] == ' ')
				i++;
			temp++;
			i++;
		}
		printf("TEMPPPPPPP = %d     LENNNNNN = %d\n", temp, len);
		if (temp > len)
			len = temp;
		tmp = get_next_line(fd);
		// free(tmp);
	}
	printf("GETNBCOOOOOLSPLITTED = %d\n", len - 1);
	return (len - 1);
}