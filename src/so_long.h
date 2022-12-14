/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:11:41 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/14 11:42:28 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_DESTROY		17
# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13

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
typedef struct s_drw
{
	int		rp;
	int		cp;
	int		re;
	int		ce;
	char	**map;
	void	*mlx;
	void	*win;
	void	*wal;
	void	*spc;
	void	*plr;
	void	*ext;
	void	*clb;
	int		dems;

}	t_drw;
t_cord	*parassign(char *file);
void	pe_pos(t_cord *cord);
char	**gen_sol(size_t rlen, size_t clen);
char	**is_aligned(char **map, size_t *rlen, size_t *clen);
int		validpath(t_cord *cord, t_cord tmp);
int		elems(char **map);
t_drw	*draw(t_cord *cord);
#endif
