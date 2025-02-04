/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:02:15 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/15 12:24:54 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_drw	*drw_init(t_cord *cord)
{
	t_drw	*drw;

	drw = ft_calloc(1, sizeof(*drw));
	if (!drw)
		return (frall(cord, NULL), NULL);
	drw->dems = 50;
	drw->mlx = mlx_init();
	if (!drw->mlx)
		return (frall(cord, drw), NULL);
	drw->win = mlx_new_window(drw->mlx, cord->clen * drw->dems, \
			cord->rlen * drw->dems, "so_long");
	if (!drw->win)
		return (frall(cord, drw), NULL);
	drw->wal = mlx_xpm_file_to_image(drw->mlx, WAL, &(drw->dems), &(drw->dems));
	drw->spc = mlx_xpm_file_to_image(drw->mlx, SPC, &(drw->dems), &(drw->dems));
	drw->plr = mlx_xpm_file_to_image(drw->mlx, PLR, &(drw->dems), &(drw->dems));
	drw->ext = mlx_xpm_file_to_image(drw->mlx, EXT, &(drw->dems), &(drw->dems));
	drw->clb = mlx_xpm_file_to_image(drw->mlx, CLB, &(drw->dems), &(drw->dems));
	if (!drw->wal || !drw->spc || !drw->plr \
			|| !drw->ext || !drw->clb)
		return (frall(cord, drw), NULL);
	drw->cord = cord;
	return (drw);
}

void	put_image(t_drw *drw, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(drw->mlx, drw->win, \
				drw->wal, j * drw->dems, i * drw->dems);
	else if (c == '0')
		mlx_put_image_to_window(drw->mlx, drw->win, \
				drw->spc, j * drw->dems, i * drw->dems);
	else if (c == 'P')
		mlx_put_image_to_window(drw->mlx, drw->win, \
				drw->plr, j * drw->dems, i * drw->dems);
	else if (c == 'C')
		mlx_put_image_to_window(drw->mlx, drw->win, \
				drw->clb, j * drw->dems, i * drw->dems);
	else if (c == 'E')
		mlx_put_image_to_window(drw->mlx, drw->win, \
				drw->ext, j * drw->dems, i * drw->dems);
}

t_drw	*draw(t_cord *cord)
{
	t_drw	*drw;
	int		i;
	int		j;

	drw = drw_init(cord);
	if (!drw)
		return (NULL);
	i = 0;
	while (cord->map[i])
	{
		j = 0;
		while (cord->map[i][j])
		{
			put_image(drw, cord->map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (drw);
}
