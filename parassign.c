#include "so_long.h"

int	fext(char *file)
{
	while(*file)
	{
		if(*file == '.' && (*(file+1) && *(file+2) && *(file+3)))
		{
			if(*(file+1) == 'b' && *(file+2) == 'e' \
					&& *(file+3) == 'r' && !*(file+4))
				return (0);
		}
		file++;
	}
	return (-1);
}

char **get_2d(char *file,  int *rlen,  int *clen)
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
	while (mfile)
	{
		tmp = mfile;	
		line = get_next_line(fd);
		mfile = ft_strjoin(mfile, line);
		free(tmp);
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
		if(fd == *clen)
			(*rlen)++;
		else
			return(ft_printf("the map is not aligned, yoo stupid\n"), NULL);
	}
	return (map);
}

int	walls(char **map, int rlen, int clen)
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
	while(map[inx][0] && map[inx][clen-1])
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
	size_t	clen;
	size_t	rlen;
	char	**map;
	t_cord  cord;

	clen = 0;
	rlen = 0;
	if (fext < 0)
		return(ft_printf("file extenstion is not '.ber', yoo stupid\n"), NULL); 
	map = get_2d(file, &rlen, &clen);
	if (!map)
			return (NULL);
	if(walls(map, rlen, clen) < 0)
		return(ft_printf("surround the map with walls, yoo stupid\n"), NULL); 
	if(PCE(map, 0, 0) < 0)
		return(ft_printf("1 C min and 1 P/E max, yoo stupid\n"), NULL); 
	if(validpath(t_cord cord) < 0)
		return(ft_printf("no valid path from P to E, yoo stupid\n"), NULL); 
}
