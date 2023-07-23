/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:52:14 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/22 21:25:55 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_xtoa(int x)
{
	char	*result;

	result = ft_calloc(2, sizeof(char));
	result[0] = x;
	return (result);
}
