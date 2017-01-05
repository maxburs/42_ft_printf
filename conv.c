/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:09:07 by mburson           #+#    #+#             */
/*   Updated: 2017/01/04 21:09:09 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

void	zero_conv(t_conv *conv)
{
	conv->letter = '\0';
	conv->flags = 0;
	conv->length = 0;
	conv->min_width = 0;
	conv->precision = 0;
}

void	print_conv(t_conv *conv)
{
	printf("---\n");
	printf("   letter: %c\n", conv->letter);
	printf("    flags: %X\n", conv->flags);
	printf("   length: %d\n", conv->length);
	printf("min_width: %d\n", conv->min_width);
	printf("precision: %d\n", conv->precision);
	printf("---\n");
}
