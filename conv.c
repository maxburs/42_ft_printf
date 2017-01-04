#include <ft_printf.h>

void	zero_conv(t_conv *conv)
{
	conv->letter = '\0';
	conv->flags = 0;
	conv->length = 0;
}