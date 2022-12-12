/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:39:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/12 14:06:46 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_cord *cord;
	size_t	inx;

	inx = 0;
	if (argc != 2)
		return (ft_printf("give valid arguments, yoo stupid\n"), -1);
	cord = parassign(argv[1]);
	return (0);
}
