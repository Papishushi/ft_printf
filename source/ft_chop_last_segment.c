/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chop_last_segment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:51:06 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 17:04:32 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	*ft_chop_last_segment(char *str, char c)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i += 2;
	result = malloc(ft_strlen(str) - i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
