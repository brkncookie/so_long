/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:46:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/23 10:48:01 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_dupextnd(char *src, size_t len, char	*ssrc, int rel)
{
	char	*dst;
	char	*s;
	char	*d;

	dst = (char *)ft_calloc(len + 1, sizeof(*dst));
	s = src;
	d = dst;
	if (dst)
	{
		while (*src && len--)
			*(dst++) = *(src++);
		if (rel)
		{
			if (ssrc)
				free (ssrc);
			else
				free(s);
		}
	}
	return (d);
}

char	*ft_strchr(char	*s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s);
			s++;
		}
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*ss;

	ss = s;
	while (*s)
			s++;
	return (((size_t)(s - ss)));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
	{
		while (count--)
			((char *)p)[count] = 0;
	}
	return (p);
}

char	*ft_condret(size_t b8rd, char **tbp)
{
	char	*lin;

	if (b8rd && *tbp)
	{
		if (*(*tbp))
		{
			lin = *tbp;
			*tbp = NULL;
			return (lin);
		}
	}
	free(*tbp);
	return (*tbp = NULL);
}
