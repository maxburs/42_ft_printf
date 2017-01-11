/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:29:26 by mburson           #+#    #+#             */
/*   Updated: 2017/01/09 21:29:27 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <string.h>
#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

static char		*ft_strpad(char *str, size_t n, char c, _Bool back)
{
	size_t	length;
	char	*result;

	length = ft_strlen(str);
	if (!(result = (char*)malloc(sizeof(char) * (length + n + 1))))
	{
		return (NULL);
	}
	result[length + n] = '\0';
	if (back)
	{
		ft_strcpy(result, str);
		ft_memset(result + length, c, n);
	}
	else
	{
		ft_strcpy(result + n, str);
		ft_memset(result, c, n);
	}
	return (result);
}

static void		format_precision(t_conv *conv, char **str)
{
	size_t	length;
	char	*swap;

	length = ft_strlen(*str);
	if (conv->precision > length)
	{
		swap = ft_strpad(*str, conv->precision - length, '0', false);
		free(*str);
		*str = swap;
	}
}

static _Bool	is_zero_fill(t_conv *conv)
{
	return ((!(conv->flags & MINUS_FLAG)) && (conv->flags & ZERO_FLAG) && (conv->precision == 0));
}

static void		format_min_width(t_conv *conv, char **str)
{
	size_t	length;
	char	*swap;

	length = ft_strlen(*str);
	if (conv->min_width > length)
	{
		swap = ft_strpad(*str, conv->min_width - length,  is_zero_fill(conv) ? '0' : ' ', (conv->flags & MINUS_FLAG));
		free(*str);
		*str = swap;
	}
}

static char		find_sign(t_conv *conv)
{
	if (conv->flags & IS_NEG)
	{
		return ('-');
	}
	else if (conv->flags & PLUS_FLAG)
	{
		return ('+');
	}
	else if (conv->flags & SPACE_FLAG)
	{
		return (' ');
	}
	else
	{
		return ('\0');
	}

}
static void		add_sign(t_conv *conv, char **str)
{
	char	*swap;
	char	sign;

	if (!(sign = find_sign(conv)))
		return ;
	if ((*str)[0] == '0')
	{
		(*str)[0] = sign;
	}
	else
	{
		if (!(swap = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 2))))
		{
			ft_strdel(str);
			return ;
		}
		ft_strcpy(swap + 1, *str);
		swap[0] = sign;
		free(*str);
		*str = swap;
	}
}

char			*format_str(t_conv *conv, char *str)
{
	format_precision(conv, &str);
	if (conv->min_width > ft_strlen(str) && is_zero_fill(conv))
	{
		format_min_width(conv, &str);
		add_sign(conv, &str);
	}
	else
	{
		add_sign(conv, &str);
		format_min_width(conv, &str);
	}
	format_min_width(conv, &str);
	return (str);
}
