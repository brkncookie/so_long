/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:50:24 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 12:34:07 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_mstrchr(char	*src,	char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_dupextnd(char *src, size_t len, char	*ssrc, int rel);
size_t	ft_strlen(const char *s);
char	*ft_condret(size_t b8rd, char **tbp);

#endif
