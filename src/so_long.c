/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:39:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 12:43:51 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char	**map;

	if(argc != 2)
		return (ft_printf("give valid arguments, yoo stupid\n"), -1);
	map = parassign(argv[1]);
	return (0);
}
