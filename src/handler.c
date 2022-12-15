/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:59:58 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/15 12:24:45 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	pupdate(t_drw *drw, int x, int y)
{
	if (x == drw->cord->rp && y == drw->cord->cp)
		return ;
	mlx_put_image_to_window(drw->mlx, drw->win, drw->spc, \
			y * drw->dems, x * drw->dems);
	mlx_put_image_to_window(drw->mlx, drw->win, drw->plr, \
			drw->cord->cp * drw->dems, drw->cord->rp * drw->dems);
}

int	key(int butt, void *parm)
{
	int		x;
	int		y;
	t_drw	*drw;

	drw = (t_drw *)parm;
	x = drw->cord->rp;
	y = drw->cord->cp;
	if ((butt == KEY_ESC || butt == X_EVENT_DESTROY))
		(mlx_destroy_window(drw->mlx, drw->win), exit(0));
	if (butt == KEY_W && drw->cord->map[x - 1][y] != '1')
		drw->cord->rp = x - 1;
	else if (butt == KEY_S && drw->cord->map[x + 1][y] != '1')
		drw->cord->rp = x + 1;
	else if (butt == KEY_D && drw->cord->map[x][y + 1] != '1')
		drw->cord->cp = y + 1;
	else if (butt == KEY_A && drw->cord->map[x][y - 1] != '1')
		drw->cord->cp = y - 1;
	if (drw->cord->map[drw->cord->rp][drw->cord->cp] == 'C')
		drw->cord->cn--;
	if (drw->cord->map[drw->cord->rp][drw->cord->cp] == 'E' && (drw->cord->cn))
		return (drw->cord->rp = x, drw->cord->cp = y, 0);
	if (drw->cord->map[drw->cord->rp][drw->cord->cp] == 'E' && !(drw->cord->cn))
		(mlx_destroy_window(drw->mlx, drw->win), exit(0));
	return (drw->cord->map[x][y] = '0', \
	drw->cord->map[drw->cord->rp][drw->cord->cp] = 'P', pupdate(drw, x, y), 0);
}

int	destroy(void *parm)
{
	key(X_EVENT_DESTROY, parm);
	return (0);
}

void	frall(t_cord *cord, t_drw *drw)
{
	int	i;
	int	j;

	i = 0;
	while (cord->map[i])
		free(cord->map[i++]);
	free(cord->map);
	j = 0;
	while (j < i)
		free(cord->sol[j++]);
	free(cord->sol);
	free(cord);
	if (drw)
	{
		mlx_destroy_image(drw->mlx, drw->wal);
		mlx_destroy_image(drw->mlx, drw->spc);
		mlx_destroy_image(drw->mlx, drw->plr);
		mlx_destroy_image(drw->mlx, drw->ext);
		mlx_destroy_image(drw->mlx, drw->clb);
		mlx_destroy_window(drw->mlx, drw->win);
		free(drw);
	}
	return ;
}
