/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:10:46 by mburson           #+#    #+#             */
/*   Updated: 2016/12/21 19:10:48 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HASH_FLAG 0x01
# define ZERO_FLAG 0x02
# define MINUS_FLAG 0x04
# define PLUS_FLAG 0x10
# define IS_NEG 0X20

# define HH_LENGTH 1
# define H_LENGTH 2
# define L_LENGTH 3
# define LL_LENGTH 4
# define J_LENGTH 5
# define Z_LENGTH 6

typedef	struct	s_conv
{
	char			letter;
	unsigned int	flags;
	unsigned int	length;
	unsigned int	min_width;
	unsigned int	precision;
}				t_conv;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);

/*
** conv.c
*/
void			zero_conv(t_conv *conv);
void			print_conv(t_conv *conv);

/*
** build_conv.c
*/
void			build_conv(const char **format, t_conv *conv);

#include <stdarg.h>
/*
** print_arg.c
*/
void			print_arg(t_conv *conv, va_list *ap);

/*
** handle_int.c
*/

 	char			*handle_int(t_conv *conv, va_list *ap);

#endif
