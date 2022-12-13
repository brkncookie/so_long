/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:02:15 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/13 15:33:24 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_drw	*draw(t_cord *cord)
{
	t_drw	*drw;
	int		i;
	int		j;

	drw = ft_calloc(1, sizeof(*drw));
	if (!drw)
		return (NULL);
	drw->dems = 50;
	drw->mlx = mlx_init();
	drw->win = mlx_new_window(drw->mlx, cord->clen * drw->dems, cord->rlen * drw->dems, "so_long");
	drw->wal = mlx_xpm_file_to_image(drw->mlx, "imgs/wal.xpm", &(drw->dems), &(drw->dems));
	drw->spc = mlx_xpm_file_to_image(drw->mlx, "imgs/spc.xpm", &(drw->dems), &(drw->dems));
	drw->plr = mlx_xpm_file_to_image(drw->mlx, "imgs/plr.xpm", &(drw->dems), &(drw->dems));
	drw->ext = mlx_xpm_file_to_image(drw->mlx, "imgs/ext.xpm", &(drw->dems), &(drw->dems));
	drw->clb = mlx_xpm_file_to_image(drw->mlx, "imgs/clb.xpm", &(drw->dems), &(drw->dems));
	drw->rp = cord->rp;
	drw->cp = cord->cp;
	drw->re = cord->re;
	drw->ce = cord->ce;
	i = 0;
	while(cord->map[i])
	{
		j = 0;
		while(cord->map[i][j])
		{
			if(cord->map[i][j] == '1')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->wal, i * drw->dems, j * drw->dems);
			else if(cord->map[i][j] == '0')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->spc, i * drw->dems, j * drw->dems);
			else if(cord->map[i][j] == 'P')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->plr,  i * drw->dems, j * drw->dems);
			else if(cord->map[i][j] == 'C')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->clb, i * drw->dems, j * drw->dems);
			else if(cord->map[i][j] == 'E')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->ext, i * drw->dems, j * drw->dems);
			j++;
		}
		i++;
	}
	mlx_loop(drw->mlx);
	return (drw);
}
