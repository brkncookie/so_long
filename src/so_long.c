/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:39:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/13 15:24:27 by mnadir           ###   ########.fr       */
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
	drw = draw(cord);
	return (0);
}
