/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:06:12 by mburson           #+#    #+#             */
/*   Updated: 2017/01/16 21:06:17 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include <libft.h>

char		*parse_str_wide(va_list *ap)
{
	va_arg(*ap, wchar_t);
	return (ft_strdup("ERROR WIDE CHARACTORS NOT SUPPORTED"));
}
