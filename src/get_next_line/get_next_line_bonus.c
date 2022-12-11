/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:09:44 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/23 12:02:37 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*nln;
	char			*lin;
	static t_file	file;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (!file.tbp[fd] && !file.b8rd[fd])
		file.tbp[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(*(file.tbp[fd])));
	while (!ft_strchr(file.tbp[fd], 10) && file.tbp[fd] && \
			read(fd, file.tbp[fd] + file.b8rd[fd], BUFFER_SIZE) > 0)
	{
		file.b8rd[fd] += BUFFER_SIZE;
		file.tbp[fd] = ft_dupextnd(file.tbp[fd], \
				(BUFFER_SIZE + file.b8rd[fd]), NULL, 1);
	}
	nln = ft_strchr(file.tbp[fd], 10);
	if (nln)
	{
		lin = ft_dupextnd(file.tbp[fd], ((nln - file.tbp[fd]) + 1), NULL, 0);
		file.b8rd[fd] -= (nln - file.tbp[fd]) + 1;
		file.tbp[fd] = ft_dupextnd(nln + 1, \
				(BUFFER_SIZE + file.b8rd[fd]), file.tbp[fd], 1);
		return (lin);
	}
	return (ft_condret(file.b8rd[fd], &(file.tbp[fd])));
}
