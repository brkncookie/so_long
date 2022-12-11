/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parassign1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:55:05 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 16:17:17 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	elems(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && \
					map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	pe_pos(t_cord *cord)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cord->map[i])
	{
		j = 0;
		while (cord->map[i][j])
		{
			if (cord->map[i][j] == 'P')
			{
				cord->rp = i;
				cord->cp = j;
			}
			else if (cord->map[i][j] == 'E')
			{
				cord->re = i;
				cord->ce = j;
			}
			j++;
		}
		i++;
	}
}

char	**gen_sol(size_t rlen, size_t clen)
{
	char	**sol;
	size_t	inx;
	size_t	tmp;

	inx = 0;
	sol = ft_calloc(rlen, sizeof(*sol));
	if (!sol)
		return (NULL);
	while (inx < rlen)
	{
		sol[inx] = ft_calloc(clen, sizeof(**sol));
		if (!sol[inx])
		{
			tmp = 0;
			while (tmp < inx && sol[tmp])
				free(sol[tmp++]);
			free(sol);
			return (NULL);
		}
		inx++;
	}
	return (sol);
}

int	validpath(t_cord cord)
{
	t_cord	tmp;

	tmp = cord;
	if ((cord.rp == cord.re) && (cord.cp == cord.ce))
		return (cord.sol[cord.rp][cord.cp] = '1', 0);
	if (cord.rp >= 0 && cord.cp >= 0 && \
			cord.rp < (int)cord.rlen && cord.cp < (int)cord.clen && \
			cord.sol[cord.rp][cord.cp] == 0 && cord.map[cord.rp][cord.cp] != 49)
	{
		cord.sol[cord.rp][cord.cp] = '1';
		tmp.rp++;
		if (validpath(tmp) > -1)
			return (0);
		tmp.rp--;
		tmp.cp++;
		if (validpath(tmp) > -1)
			return (0);
		tmp.cp--;
		tmp.rp--;
		if (validpath(tmp) > -1)
			return (0);
		tmp.rp++;
		tmp.cp--;
		if (validpath(tmp) > -1)
			return (0);
		return (cord.sol[cord.rp][cord.cp] = 0, -1);
	}
	return (-1);
}
