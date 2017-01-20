/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:08:33 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 23:08:34 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <string.h>
#include <stdint.h>

static const int	g_length_index[] = {
	sizeof(int) * 8,
	sizeof(char) * 8,
	sizeof(short) * 8,
	sizeof(long) * 8,
	sizeof(long long) * 8,
	sizeof(intmax_t) * 8,
	sizeof(size_t) * 8
};

static void		inference_b(t_conv *conv)
{
	if (!(conv->flags & HAS_PRECISION))
		conv->precision = g_length_index[conv->length];
}

static void		inference_s_alt(t_conv *conv)
{
	if (conv->precision == 0)
	{
		conv->precision = 8;
	}
}

void			inference(t_conv *conv)
{
	if (conv->letter == 'b')
		inference_b(conv);
	if (conv->letter == 's' && (conv->flags & HASH_FLAG))
		inference_s_alt(conv);
}
