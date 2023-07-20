/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:52:14 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 16:53:34 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_xtoa(int x)
{
	char	*result;

	result = malloc(2);
	result[0] = x;
	result[1] = '\0';
	return (result);
}
