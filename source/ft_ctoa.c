/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:52:26 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/23 01:38:13 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_ctoa(char c)
{
	char	*result;

	if (!c)
		return (ft_calloc(1, sizeof(char)));
	result = ft_calloc(2, sizeof(char));
	if (result == NULL)
		return (0);
	result[0] = c;
	return (result);
}
