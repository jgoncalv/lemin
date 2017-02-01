/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:20:08 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/15 12:11:42 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef	struct	s_flag
{
	int			sharp;
	int			zero;
	int			space;
	int			negative;
	int			positive;
	int			width_min;
	int			precision_ok;
	int			precision;
	enum	{
		none,
		hh,
		h,
		ll,
		l,
		j,
		z
	}			length_modifier;
}				t_flag;

int				ft_printf(const char *format, ...);
void			ft_check_flag(char **format, t_flag *flag);
void			ft_check_width(char **format, t_flag *flag);
void			ft_check_modifier(char **format, t_flag *flag);
void			ft_check_precision(char **format, t_flag *flag);
int				ft_check_flag_base(va_list arg, char c, t_flag *flag);
int				ft_printf_itoa(intmax_t n, t_flag *flag);
int				ft_printf_uitoa_base(uintmax_t n, int base,
				t_flag *flag, char c);
int				ft_printf_s(char *str, t_flag *flag);
int				ft_printf_ws(wchar_t *wstr, t_flag *flag);
int				ft_printf_c(char c, t_flag *flag);
int				ft_printf_wc(wchar_t c, t_flag *flag);
int				ft_printf_percent(t_flag *flag);
int				ft_printf_p(unsigned long n, t_flag *flag);
intmax_t		ft_modifier_di(va_list arg, t_flag *flag);
uintmax_t		ft_modifier_oux(va_list arg, t_flag *flag);
int				ft_check_flag_base(va_list arg, char c, t_flag *flag);
int				ft_printf_dioux(va_list arg, char c, t_flag *flag);
#endif
