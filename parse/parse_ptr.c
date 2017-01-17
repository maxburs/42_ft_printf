/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:09 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:48 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <stdlib.h>

char		*parse_ptr(va_list *ap)
{
	void	*ptr;
	size_t	size;
	t_conv	tmp_conv;
	char	*str1;
	char	*str2;

	zero_conv(&tmp_conv);
	size = sizeof(void*);
	tmp_conv.letter = 'x';
	tmp_conv.precision = size * 2;
	ptr = (void*)va_arg(*ap, void*);
	str1 = num_to_string(&tmp_conv, (uintmax_t)ptr);
	str2 = ft_strjoin("0x", str1);
	free(str1);
	return (str2);
}
