/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_segment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:48:34 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 16:54:39 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	ft_get_next_segment(char *flags, char c)
{
	char	*tmp;

	tmp = ft_strchr(flags, c);
	if (tmp == 0)
		return (0);
	return (*(tmp + 1));
}
