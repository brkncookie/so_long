/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:59:06 by mnadir            #+#    #+#             */
/*   Updated: 2022/11/04 11:28:26 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_fsi	*ft_fsinit(char *fmt, char *fmt0)
{
	t_fsi	*fsi;
	size_t	inx;

	fsi = ft_calloc(1, sizeof(*fsi));
	if (!fsi)
		return (NULL);
	while (fmt0 && *fmt0)
	{
		fmt0 = ft_strchr(fmt0, '%');
		if (fmt0 && *(++fmt0) && ft_strchr("cspdiuxX%", *(fmt0++)))
				fsi->cnt++;
	}
	fsi->fsp = ft_calloc(fsi->cnt + 1, sizeof(*(fsi->fsp)));
	if (!(fsi->fsp))
		return (free(fsi), NULL);
	inx = 0;
	while (fmt && inx < fsi->cnt)
	{
		fmt = ft_strchr(fmt, '%');
		fsi->fsp[inx] = fmt;
		if (fmt && *(++fmt) && ft_strchr("cspdiuxX%", *(fmt++)))
			inx++;
	}
	return (fsi);
}

char	**ft_resfs(t_fsi *fsi, va_list *ap)
{
	char	**rfs;
	size_t	inx;

	rfs = ft_calloc(fsi->cnt + 1, sizeof(*rfs));
	if (!rfs)
		return (free(fsi->fsp), free(fsi), NULL);
	inx = 0;
	while (fsi->fsp[inx])
	{
		rfs[inx] = ft_getd(fsi->fsp[inx][1], ap);
		if (!(rfs[inx]))
			return (ft_frall(NULL, rfs, fsi));
		inx++;
	}
	return (rfs);
}

char	*ft_bldstr(char *fmt, char **rfs, t_fsi *fsi, size_t *rslen)
{
	size_t	inx;
	char	*rstr;

	if (!rfs)
		return (NULL);
	inx = 0;
	*rslen = ft_strlen(fmt) - (2 * fsi->cnt);
	while (rfs[inx++])
		*rslen += ft__strlen(rfs[inx - 1], fsi->fsp[inx - 1][1]);
	rstr = ft_calloc(*rslen + 1, sizeof(*rstr));
	if (!rstr)
		return (ft_frall(NULL, rfs, fsi));
	inx = 0;
	while (*fmt)
	{
		if (fmt == fsi->fsp[inx] && fmt++ && fmt++)
		{
			ft_memcpy(rstr, rfs[inx], ft__strlen(rfs[inx], fsi->fsp[inx][1]));
			rstr += ft__strlen(rfs[inx], fsi->fsp[inx][1]);
			inx++;
			continue ;
		}
		*(rstr++) = *(fmt++);
	}
	return (rstr - *rslen);
}

int	ft_printf(const char *fmt, ...)
{
	char	**rfs;
	char	*rstr;
	t_fsi	*fsi;
	size_t	len;
	va_list	ap;

	fsi = ft_fsinit((char *)fmt, (char *)fmt);
	if (!fsi)
		return (-1);
	if (!fsi->cnt)
		return (free(fsi->fsp), free(fsi), write(1, fmt, ft_strlen(fmt)));
	va_start(ap, fmt);
	rstr = ft_bldstr((char *)fmt, rfs = ft_resfs(fsi, &ap), fsi, &len);
	if (!rstr)
		return (-2);
	va_end(ap);
	write(1, rstr, len);
	return (ft_frall(rstr, rfs, fsi), len);
}
