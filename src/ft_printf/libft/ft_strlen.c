/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:24:52 by mnadir            #+#    #+#             */
/*   Updated: 2022/11/03 09:27:21 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* this time let's do it a lil bit (or byte) differently */
size_t	ft_strlen(const char *s)
{
	const char	*ss;

	ss = s;
	while (*s)
			s++;
	return (((size_t)(s - ss)));
}

size_t	ft__strlen(const char *s, char c)
{
	size_t	l;

	l = 0;
	if (!*s && c == 'c')
		l++;
	while (*s++)
		l++;
	return (l);
}
