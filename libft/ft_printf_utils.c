/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:47:39 by mnadir            #+#    #+#             */
/*   Updated: 2022/11/03 10:21:05 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_getd(char c, va_list *ap)
{
	if (c == 's')
		return (ft_str(ap));
	else if (c == 'c')
		return (ft_cha(ap));
	else if (c == 'x' || c == 'X')
		return (ft_unsx(ap, c, 0));
	else if (c == 'p')
		return (ft_ptr(ap));
	else if (c == 'u')
		return (ft_unsx(ap, c, 1));
	else if (c == 'i' || c == 'd')
		return (ft_int(ap));
	else
		return (ft_strdup("%"));
}

void	*ft_frall(char	*rstr, char	**rfs, t_fsi	*fsi)
{
	size_t	inx;

	inx = 0;
	while (rfs[inx])
		free (rfs[inx++]);
	return (free(rfs), free(rstr), free(fsi->fsp), free(fsi), NULL);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	i;
	size_t			l;
	char			*uc;

	l = 0;
	i = n;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		n /= 10;
		l++;
	}
	uc = ft_calloc(l + 1, sizeof(*uc));
	if (!uc)
		return (NULL);
	n = i;
	while (n)
	{
		uc[--l] = "0123456789"[n % 10];
		n /= 10;
	}
	return (uc);
}

char	*ft_i2hx(unsigned int n, char X, char *hx, char *hex)
{
	unsigned int	i;
	size_t			l;

	l = 0;
	i = n;
	hex = "0123456789abcdef";
	if (!n)
		return (ft_strdup("0"));
	if (X == 'X')
		hex = "0123456789ABCDEF";
	while (n)
	{
		n /= 16;
		l++;
	}
	hx = ft_calloc(l + 1, sizeof(*hx));
	if (!hx)
		return (NULL);
	n = i;
	while (n)
	{
		hx[--l] = hex[n % 16];
		n /= 16;
	}
	return (hx);
}

char	*ft_p2hx(void *p)
{
	unsigned long	n;
	size_t			l;
	char			*hx;

	l = 2;
	n = (unsigned long)p;
	if (!p)
		return (ft_strdup("0x0"));
	while (n)
	{
		n /= 16;
		l++;
	}
	hx = ft_calloc(l + 1, sizeof(*hx));
	if (!hx)
		return (NULL);
	hx[0] = '0';
	hx[1] = 'x';
	n = (unsigned long)p;
	while (n)
	{
		hx[--l] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (hx);
}
