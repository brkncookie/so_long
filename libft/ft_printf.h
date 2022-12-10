/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:55:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/11/05 10:21:40 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_fsi
{
	char	**fsp;
	size_t	cnt;
}	t_fsi;
char	*ft_utoa(unsigned int n);
char	*ft_i2hx(unsigned int n, char X, char *hx, char *hex);
char	*ft_p2hx(void *p);
int		ft_printf(const char *fmt, ...);
char	*ft_getd(char c, va_list *ap);
void	*ft_frall(char	*rstr, char	**rfs, t_fsi	*fsi);
/* format strings functions => fsf */
char	*ft_str(va_list *ap);
char	*ft_cha(va_list *ap);
char	*ft_ptr(va_list *ap);
char	*ft_int(va_list *ap);
char	*ft_unsx(va_list *ap, char X, int u);
#endif
