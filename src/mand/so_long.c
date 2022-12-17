/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:39:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/17 14:03:38 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_cord	*cord;
	t_drw	*drw;

	if (argc != 2)
		return (ft_printf("give valid arguments, yoo stoopid\n"), -1);
	cord = parassign(argv[1]);
	if (cord)
	{
		drw = draw(cord);
		if (drw)
		{
			mlx_hook(drw->win, X_EVENT_KEY_PRESS, 0, key, drw);
			mlx_hook(drw->win, X_EVENT_DESTROY, 0, destroy, drw);
			mlx_key_hook(drw->win, key, drw);
			mlx_loop(drw->mlx);
		}
	}
	return (0);
}
