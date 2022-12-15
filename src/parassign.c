/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parassign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:21:42 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/15 10:52:12 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fext(char *file)
{
	while (*file)
	{
		if (*file == '.' && (*(file + 1) && *(file + 2) && *(file + 3)))
		{
			if (*(file + 1) == 'b' && *(file + 2) == 'e' \
					&& *(file + 3) == 'r' && !*(file + 4))
				return (0);
		}
		file++;
	}
	return (-1);
}

char	**get_2d(char *file, size_t *rlen, size_t *clen)
{
	int		fd;
	char	*mfile;
	char	*tmp;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0 && ft_printf("%s\n", strerror(errno)))
		exit(errno);
	mfile = ft_calloc(1, sizeof(*mfile));
	line = mfile;
	while (mfile && line)
	{
		tmp = mfile;
		line = get_next_line(fd);
		if (line)
		{
			mfile = ft_strjoin(mfile, line);
			free(tmp);
		}
		free(line);
	}
	close(fd);
	map = is_aligned(ft_split(mfile, '\n'), rlen, clen);
	return (free(mfile), map);
}

int	walls(char **map, size_t rlen, size_t clen)
{
	int	inx;

	inx = 0;
	while (map[0][inx])
	{
		if (map[0][inx++] != '1')
			return (-1);
	}
	inx = 0;
	while (map[rlen - 1][inx])
	{
		if (map[rlen - 1][inx++] != '1')
			return (-1);
	}
	inx = 0;
	while (map[inx] && map[inx][0] && map[inx][clen - 1])
	{
		if (map[inx][0] != '1' || map[inx][clen - 1] != '1')
			return (-1);
		inx++;
	}
	return (0);
}

int	pce(char **map, int i, int j, int *c)
{
	int	p;
	int	e;

	p = 0;
	*c = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
	if (p != 1 || *c == 0 || e != 1)
		return (-1);
	return (0);
}

t_cord	*parassign(char *file)
{
	t_cord	*cord;

	cord = ft_calloc(1, sizeof(*cord));
	if (!cord)
		return (NULL);
	cord->rlen = 0;
	cord->clen = 0;
	if (fext(file) < 0)
		return (ft_printf("file extenstion is not '.ber'\n"), free(cord), NULL);
	cord->map = get_2d(file, &(cord->rlen), &(cord->clen));
	if (!(cord->map))
		return (free(cord), NULL);
	if (elems(cord->map) < 0)
		return (ft_printf("use the given chars\n"), frall(cord, NULL), NULL);
	if (walls(cord->map, cord->rlen, cord->clen) < 0)
		return (ft_printf("surround  with walls\n"), frall(cord, NULL), NULL);
	if (pce(cord->map, 0, 0, &(cord->cn)) < 0)
		return (ft_printf("1 C min and 1 P/E max\n"), frall(cord, NULL), NULL);
	pe_pos(cord);
	cord->sol = gen_sol(cord->rlen, cord->clen);
	if (!(cord->sol))
		return (frall(cord, NULL), NULL);
	if (validpath(cord, *cord) < 0)
		return (ft_printf("no valid path from P2E\n"), frall(cord, NULL), NULL);
	return (cord);
}
