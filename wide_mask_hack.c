/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_mask_hack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:42:58 by mburson           #+#    #+#             */
/*   Updated: 2017/01/26 21:43:00 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wchar.h>
#include <libft.h>

unsigned char		*ft_utf_32_8_mask(wint_t c)
{
	char	*str;

	str = ft_strdup(" ");
	str[0] = c;
	return ((unsigned char*)str);
}
