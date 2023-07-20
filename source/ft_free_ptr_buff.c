/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:45:59 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/18 19:46:36 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_free_ptr_buff(char **buff, int lenght)
{
	int	i;

	i = 0;
	if(!buff || lenght <= 0)
		return ;
	while (i < lenght)
		free(*(buff + i++));
	free(buff);
}
