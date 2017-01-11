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
# define SPACE_FLAG 0x20
# define IS_NEG 0x40

# define HH_LENGTH 1
# define H_LENGTH 2
# define L_LENGTH 3
# define LL_LENGTH 4
# define J_LENGTH 5
# define Z_LENGTH 6

# include <stdarg.h>
# include <string.h>
# include <stdint.h>

typedef	struct	s_conv
{
	char			letter;
	unsigned int	flags;
	unsigned int	length;
	size_t			min_width;
	size_t			precision;
}				t_conv;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);

/*
** conv.c
*/
void			build_conv(const char **format, t_conv *conv);
void			zero_conv(t_conv *conv);

/*
** parse.c
*/
char			*parse(t_conv *conv, va_list *ap);

/*
** parse_int.c
*/
char			*parse_int(t_conv *conv, va_list *ap);
char			*num_to_string(t_conv *conv, uintmax_t num);

/*
** format.c
*/
char			*format_str(t_conv *conv, char *str);

/*
** debug.c
*/
void			print_conv(t_conv *conv);

/*
** parse_ptr.c
*/
char			*parse_ptr(va_list *ap);

#endif
