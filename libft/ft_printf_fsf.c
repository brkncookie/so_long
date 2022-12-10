/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fsf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:46:30 by mnadir            #+#    #+#             */
/*   Updated: 2022/11/03 09:51:56 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_str(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char	*ft_int(va_list *ap)
{
	return (ft_itoa(va_arg(*ap, int)));
}

char	*ft_ptr(va_list *ap)
{
	return (ft_p2hx(va_arg(*ap, void *)));
}

char	*ft_cha(va_list *ap)
{
	char	*c;

	c = ft_calloc(2, sizeof(*c));
	if (!c)
		return (NULL);
	*c = (unsigned char)va_arg(*ap, int);
	return (c);
}

char	*ft_unsx(va_list *ap, char X, int u)
{
	char	*hx;

	if (u)
		return (ft_utoa(va_arg(*ap, unsigned int)));
	hx = ft_i2hx(va_arg(*ap, unsigned int), X, NULL, NULL);
	if (!hx)
		return (NULL);
	return (hx);
}
