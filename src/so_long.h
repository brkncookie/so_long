/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:11:41 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 15:56:07 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_cord
{
	int		rp;
	int		cp;
	int		re;
	int		ce;
	size_t	rlen;
	size_t	clen;
	char	**map;
	char	**sol;
}	t_cord;
char	**parassign(char *file);
void	pe_pos(t_cord *cord);
char	**gen_sol(size_t rlen, size_t clen);
int		validpath(t_cord cord);
int		elems(char **map);
#endif
