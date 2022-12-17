/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:47:12 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/11 12:37:19 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*nln;
	char			*lin;
	static char		*tbp = NULL;
	static size_t	b8rd = 0;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (!tbp && !b8rd)
		tbp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(*tbp));
	while (!ft_mstrchr(tbp, 10) && tbp && read(fd, tbp + b8rd, BUFFER_SIZE) > 0)
	{
		b8rd += BUFFER_SIZE;
		tbp = ft_dupextnd(tbp, (BUFFER_SIZE + b8rd), NULL, 1);
	}
	nln = ft_mstrchr(tbp, 10);
	if (nln)
	{
		lin = ft_dupextnd(tbp, ((nln - tbp) + 1), NULL, 0);
		b8rd -= (nln - tbp) + 1;
		tbp = ft_dupextnd(nln + 1, (BUFFER_SIZE + b8rd), tbp, 1);
		return (lin);
	}
	return (ft_condret(b8rd, &tbp));
}
