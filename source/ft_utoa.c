/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:52:18 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/20 16:53:21 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_putnbr_sp(unsigned int *nb, char *buffer)
{
	char	temp;

	if (*nb < 10)
	{
		temp = *nb + '0';
		buffer[0] = temp;
		return (0);
	}
	return (1);
}

char	*ft_utoa(unsigned int u)
{
	char	buffer[12];
	char	reverse_buffer[12];
	size_t	lenght;
	size_t	i;

	lenght = 0;
	ft_memset(reverse_buffer, 0, 12 * sizeof(char));
	ft_memset(buffer, 0, 12 * sizeof(char));
	if (!ft_putnbr_sp(&u, buffer))
		return (ft_strdup(buffer));
	i = 0;
	while (u >= 1)
	{
		reverse_buffer[lenght++] = (u % 10) + '0';
		u /= 10;
	}
	while (i <= lenght)
	{
		buffer[i] = reverse_buffer[lenght - i - 1];
		i++;
	}
	return (ft_strdup(buffer));
}
