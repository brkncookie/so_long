/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parassign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:21:42 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 15:56:18 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fext(char *file)
{
	while (*file)
	{
		if (*file == '.' && (*(file+1) && *(file+2) && *(file+3)))
		{
			if(*(file+1) == 'b' && *(file+2) == 'e' \
					&& *(file+3) == 'r' && !*(file+4))
				return (0);
		}
		file++;
	}
	return (-1);
}

char **get_2d(char *file,  size_t *rlen,  size_t *clen)
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
		if(line)
		{
			mfile = ft_strjoin(mfile, line);
			free(tmp);
		}
		free(line);
	}
	close(fd);
	map = ft_split(mfile, '\n');
	free(mfile);
	while(map && map[0][*clen])
		(*clen)++;
	while(map && map[*rlen])
	{
		fd = 0;
		while(map[*rlen][fd])
			fd++;
		if(fd == (int)*clen)
			(*rlen)++;
		else
			return(ft_printf("the map is not aligned, yoo stoopid\n"), NULL);
	}
	return (map);
}

int	walls(char **map, size_t rlen, size_t clen)
{
	int	inx;
	
	inx = 0;
	while(map[0][inx])
	{
		if(map[0][inx++] != '1')
			return(-1);
	}
	inx = 0;
	while(map[rlen-1][inx])
	{
		if(map[rlen-1][inx++] != '1')
			return(-1);
	}
	inx = 0;
	while(map[inx] && map[inx][0] && map[inx][clen-1])
	{
		if(map[inx][0] != '1' || map[inx][clen-1] != '1')
			return(-1);
		inx++;
	}
	return(0);
}

int	PCE(char **map, int i, int j)
{
	int	P;
	int	C;
	int	E;

	P = 0;
	C = 0;
	E = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				P++;
			else if (map[i][j] == 'E')
				E++;
			else if (map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	if(P != 1 || C == 0 || E != 1)
		return (-1);
	return(0);
}

char	**parassign(char *file)
{
	t_cord  cord;

	cord.rlen = 0;
	cord.clen = 0;
	if (fext(file) < 0)
		return(ft_printf("file extenstion is not '.ber', yoo stoopid\n"), NULL); 
	cord.map = get_2d(file, &(cord.rlen), &(cord.clen));
	if (!(cord.map))
			return (NULL);
	if(elems(cord.map) < 0)
		return(ft_printf("use only the provided characters, yoo stoopid\n"), NULL); 
	if(walls(cord.map, cord.rlen, cord.clen) < 0)
		return(ft_printf("surround the map with walls, yoo stoopid\n"), NULL); 
	if(PCE(cord.map, 0, 0) < 0)
		return(ft_printf("1 C min and 1 P/E max, yoo stoopid\n"), NULL); 
	pe_pos(&cord);
	cord.sol = gen_sol(cord.rlen, cord.clen);
	if(!cord.sol)
		return (NULL);
	if(validpath(cord) < 0)
		return(ft_printf("no valid path from P to E, yoo stoopid\n"), NULL); 
	return(cord.map);
}
