/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:11:41 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/15 12:26:45 by mnadir           ###   ########.fr       */
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
# define WAL					"imgs/wal.xpm"
# define SPC					"imgs/spc.xpm"
# define PLR					"imgs/plr.xpm"
# define EXT					"imgs/ext.xpm"
# define CLB					"imgs/clb.xpm"

typedef struct s_cord
{
	int		rp;
	int		cp;
	int		re;
	int		ce;
	int		cn;
	size_t	rlen;
	size_t	clen;
	char	**map;
	char	**sol;
}	t_cord;
typedef struct s_drw
{
	t_cord	*cord;
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
t_drw	*draw(t_cord *cord);
int		validpath(t_cord *cord, t_cord tmp);
void	pe_pos(t_cord *cord);
char	**gen_sol(size_t rlen, size_t clen);
char	**is_aligned(char **map, size_t *rlen, size_t *clen);
int		elems(char **map);
void	frall(t_cord *cord, t_drw *drw);
int		key(int butt, void *parm);
int		destroy(void *parm);
#endif
