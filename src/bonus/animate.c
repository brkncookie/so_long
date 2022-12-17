/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:13:20 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/17 12:47:49 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	drw_ext(t_drw *drw)
{
	drw->ext2 = mlx_xpm_file_to_image(drw->mlx, EXT2, \
			&(drw->dems), &(drw->dems));
	drw->ext3 = mlx_xpm_file_to_image(drw->mlx, EXT3, \
			&(drw->dems), &(drw->dems));
	drw->ext4 = mlx_xpm_file_to_image(drw->mlx, EXT4, \
			&(drw->dems), &(drw->dems));
	drw->ext5 = mlx_xpm_file_to_image(drw->mlx, EXT5, \
			&(drw->dems), &(drw->dems));
	drw->ext6 = mlx_xpm_file_to_image(drw->mlx, EXT6, \
			&(drw->dems), &(drw->dems));
	drw->ext7 = mlx_xpm_file_to_image(drw->mlx, EXT7, \
			&(drw->dems), &(drw->dems));
}

void	animate(t_drw *drw, int i)
{
	if (i == 0)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 1000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext2, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 2000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext3, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 3000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext4, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 4000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext5, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 5000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext6, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
	if (i == 6000)
		mlx_put_image_to_window(drw->mlx, drw->win, drw->ext7, \
		drw->cord->ce * drw->dems, drw->cord->re * drw->dems);
}

int	frame_update(void)
{
	static int	i = 0;

	if (i < 6000)
		i++;
	else
		i = 0;
	return (i);
}

int	render(t_drw *drw)
{
	animate(drw, frame_update());
	return (0);
}
