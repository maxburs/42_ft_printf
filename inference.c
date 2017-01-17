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

static const int	length_index[] = {
	sizeof(char),
	sizeof(short),
	sizeof(long),
	sizeof(long long),
	sizeof(intmax_t),
	sizeof(size_t)
};

static void		set_letter_d_precision(t_conv *conv)
{
	conv->precision = length_index[conv->length];
}

void			inference(t_conv *conv)
{
	if (conv->letter == 'd')
		set_letter_d_precision(conv);
}
