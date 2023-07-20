/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:07 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 17:03:13 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdint.h>
#include <stdio.h>

struct s_print_handle	*parse_flags(char *input, va_list *flag_list)
{
	struct s_print_handle	*handle;
	char					**buff;
	char					flag;
	int						i;

	i = 0;
	buff = calloc(4096, sizeof(char *));
	if (!buff)
		return (NULL);
	handle = malloc(sizeof(struct s_print_handle));
	if (!handle)
		return (NULL);
	handle->input = ft_strdup(input);
	while (input && *input)
	{
		flag = ft_get_next_segment(input, '%');
		input = ft_chop_last_segment(input, '%');
		if (flag == 'c')
			*(buff + i++) = ft_ctoa(va_arg(*flag_list, int));
		else if (flag == 's')
			*(buff + i++) = ft_strdup(va_arg(*flag_list, char *));
		else if (flag == 'p')
			*(buff + i++) = ft_utoa((uintptr_t)va_arg(*flag_list, void *));
		else if (flag == 'd')
			*(buff + i++) = ft_itoa(va_arg(*flag_list, int));
		else if (flag == 'i')
			*(buff + i++) = ft_itoa(va_arg(*flag_list, int));
		else if (flag == 'u')
			*(buff + i++) = ft_utoa(va_arg(*flag_list, unsigned int));
		else if (flag == 'x')
			*(buff + i++) = ft_xtoa(va_arg(*flag_list, int));
		else if (flag == 'X')
			*(buff + i++) = ft_xxtoa(va_arg(*flag_list, int));
		else if (flag == '%')
			*(buff + i++) = ft_ctoa('%');
		else
			break ;
	}
	handle->parsed_flags = buff;
	handle->lenght = i;
	return (handle);
}

void	free_print_handle(struct s_print_handle *handle)
{
	free(handle->input);
	ft_free_ptr_buff(handle->parsed_flags, handle->lenght);
	free(handle);
}

int	get_parsed_flags_lenght(const struct s_print_handle *handle)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (i < handle->lenght)
		lenght += ft_strlen(handle->parsed_flags[i++]);
	return (lenght);
}

void	interpret_loop(const struct s_print_handle *handle, char *result, int input_lenght)
{
	int		i;
	int		ri;
	int		fi;
	int		pi;

	i = -1;
	ri = 0;
	pi = 0;
	while (++i < input_lenght)
	{
		if (!handle->input[i])
			result[ri] = '\0';
		else if (handle->input[i] != '%')
			result[ri++] = handle->input[i];
		else if (handle->input[i] == '%')
		{
			i += 2;
			fi = 0;
			if (handle->parsed_flags == NULL || handle->parsed_flags[pi] == NULL)
				break ;
			while(handle->parsed_flags[pi][fi] != '\0')
				result[ri++] = handle->parsed_flags[pi][fi++];
			pi++;
		}
	}
}

int	interpret_handle(const struct s_print_handle *handle)
{
	char	*result;
	int		count;
	int		input_lenght;

	if (handle->input == NULL)
		return (0);
	input_lenght = ft_strlen(handle->input);
	count = input_lenght - (2 * handle->lenght) + get_parsed_flags_lenght(handle);
	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (0);
	result[count] = '\0';
	interpret_loop(handle, result, input_lenght);
	write(1, result, count);
	free(result);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list					args;
	int						count;
	struct s_print_handle	*handle;
	char					*str_copy;

	va_start(args, str);
	str_copy = ft_strdup(str);
	if (str_copy == NULL)
		return (0);
	handle = parse_flags(str_copy ,&args);
	if (handle == NULL)
		return (0);
	count = interpret_handle(handle);
	free_print_handle(handle);
	va_end(args);
	return (count);
}
