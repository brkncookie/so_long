/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:02:15 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/14 13:54:37 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	pupdate(t_drw *drw, int x, int y)
{
	mlx_put_image_to_window(drw->mlx, drw->win, drw->spc, y * drw->dems, x * drw->dems);
	mlx_put_image_to_window(drw->mlx, drw->win, drw->plr, drw->cp * drw->dems, drw->rp * drw->dems);
}
int	key(int butt, void *parm)
{
	int		x;
	int		y;
	t_drw	*drw;
	
	drw = (t_drw *)parm;
	x = drw->rp;
	y = drw->cp;
	if (butt == KEY_ESC || butt == X_EVENT_DESTROY)
	{
		mlx_destroy_window(drw->mlx, drw->win);
		exit(0);
	}
	if(butt == KEY_W && drw->map[x - 1][y] != '1')
	{
		drw->map[x - 1][y] = 'P';
		drw->map[x][y] = '0';
		drw->rp = x - 1;
	}
	else if(butt == KEY_S && drw->map[x + 1][y] != '1')
	{
		drw->map[x + 1][y] = 'P';
		drw->map[x][y] = '0';
		drw->rp = x + 1;
	}
	else if(butt == KEY_D && drw->map[x][y + 1] != '1')
	{
		drw->map[x][y + 1] = 'P';
		drw->map[x][y] = '0';
		drw->cp = y + 1;
	}
	else if(butt == KEY_A && drw->map[x][y - 1] != '1')
	{
		drw->map[x][y - 1] = 'P';
		drw->map[x][y] = '0';
		drw->cp = y - 1;
	}
	if(x != drw->rp || y != drw->cp)
		pupdate(drw, x, y);
	return (0);
}
int	destroy(void *parm)
{
	key(X_EVENT_DESTROY, parm);
	return (0);
}
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
	drw->map = cord->map;
	i = 0;
	while (cord->map[i])
	{
		j = 0;
		while (cord->map[i][j])
		{
			if (cord->map[i][j] == '1')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->wal, j * drw->dems, i * drw->dems);
			else if (cord->map[i][j] == '0')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->spc, j * drw->dems, i * drw->dems);
			else if (cord->map[i][j] == 'P')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->plr, j * drw->dems, i * drw->dems);
			else if (cord->map[i][j] == 'C')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->clb, j * drw->dems, i * drw->dems);
			else if (cord->map[i][j] == 'E')
				mlx_put_image_to_window(drw->mlx, drw->win, drw->ext, j * drw->dems, i * drw->dems);
			j++;
		}
		i++;
	}
	mlx_hook(drw->win, X_EVENT_DESTROY, 0, destroy, drw);
	mlx_key_hook(drw->win, key, drw);
	mlx_loop(drw->mlx);
	return (drw);
}
