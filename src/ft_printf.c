/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:12:51 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 16:45:50 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_choice(const char *format, size_t i, va_list arg_list)
{
	int	nbchar;

	if (format[i + 1] == 'c')
		nbchar = ft_printfchar(va_arg(arg_list, int));
	if (format[i + 1] == 's')
		nbchar = ft_printfstr(va_arg(arg_list, char *));
	if (format[i + 1] == 'p')
		nbchar = ft_printfpointer(va_arg(arg_list, unsigned long long),
				"0123456789abcdef");
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		nbchar = ft_printfnbr(va_arg(arg_list, int));
	if (format[i + 1] == 'u')
		nbchar = ft_printfunbr(va_arg(arg_list, unsigned int));
	if (format[i + 1] == 'x')
		nbchar = ft_printfhex(va_arg(arg_list, unsigned int),
				"0123456789abcdef");
	if (format[i + 1] == 'X')
		nbchar = ft_printfhex(va_arg(arg_list, unsigned int),
				"0123456789ABCDEF");
	if (format[i + 1] == '%')
		nbchar = ft_printfchar('%');
	return (nbchar);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	size_t	i;
	int		nbchar;

	va_start(arg_list, format);
	i = 0;
	nbchar = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			nbchar += ft_choice(format, i, arg_list);
			i += 2;
		}
		else
		{
			ft_putchar(format[i++]);
			nbchar++;
		}
	}
	va_end(arg_list);
	return (nbchar);
}
