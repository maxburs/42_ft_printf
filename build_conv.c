/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:10:31 by mburson           #+#    #+#             */
/*   Updated: 2017/01/04 23:10:32 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdbool.h>

static const char *format_characters = "sSpdDioOuUxXcC";

static const char *flag_keys = "#0-+";
static const int flag_values[] = {
	HASH_FLAG,
	ZERO_FLAG,
	MINUS_FLAG,
	PLUS_FLAG
};

static const char *length_values_1 = "__hl_jz";
static const char *length_values_2 = "_h__l";


static unsigned int		match_flags(char c)
{
	int		match;

	match = ft_strchri(flag_keys, c);
	if (match == -1)
	{
		return (false);
	}
	return (flag_values[match]);
}

static unsigned int		match_length(char c, unsigned int current_len)
{
	int		match;

	match = ft_strchri(length_values_1, c);
	if (match == -1)
	{
		return (false);
	}
	if ((unsigned int)match == current_len)
	{
		return (ft_strchri(length_values_2, c));
	}
	return (match);
}

void					build_conv(const char **format, t_conv *conv)
{
	int		match;

	match = 0;
	zero_conv(conv);
	while (!conv->letter)
	{
		if (ft_strchri(format_characters, **format) != -1)
		{
			conv->letter = **format;
		}
		else if ((match = match_flags(**format)))
		{
			conv->flags = conv->flags | match;
		}
		else if ((match = match_length(**format, conv->length)))
		{
			conv->length = match;
		}
		(*format)++;
	}
}
