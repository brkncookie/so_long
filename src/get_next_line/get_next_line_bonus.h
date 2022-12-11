/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:47:38 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/23 12:09:04 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(char	*src,	char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_dupextnd(char *src, size_t len, char	*ssrc, int rel);
size_t	ft_strlen(const char *s);
char	*ft_condret(size_t b8rd, char **tbp);

typedef struct s_file
{
	char	*tbp[OPEN_MAX];
	size_t	b8rd[OPEN_MAX];
}	t_file;

#endif
