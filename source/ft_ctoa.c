/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:52:26 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 16:52:46 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_ctoa(char c)
{
	char	*result;

	result = malloc(2);
	if (result == NULL)
		return (0);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
