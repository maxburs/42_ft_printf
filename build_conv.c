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

static const char *format_characters = "sSpdDioOuUxXcC";

static const char *flag_keys = "#0-+";

static const int flag_values[] = {
	HASH_FLAG,
	ZERO_FLAG,
	MINUS_FLAG,
	PLUS_FLAG
};


static int		match_flags(char c)
{
	int		match;

	match = ft_strchri(flag_keys, c);
	if (match == -1)
		return (0);
	else
		return (flag_values[match]);
}

static int		match_length(char c)
{
	c++;
	return (0);
}

void			build_conv(const char **format, t_conv *conv)
{
	int		match;

	match = 0;
	zero_conv(conv);
	while (!conv->letter)
	{
		if (ft_strchri(format_characters, **format) != -1)
			conv->letter = **format;
		else if ((match = match_flags(**format)))
			conv->flags = conv->flags | match;
		else if ((match = match_length(**format)))
			conv->length = match;
		(*format)++;
	}
}
