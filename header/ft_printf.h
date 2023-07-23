/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:12:04 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/23 00:30:14 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

struct s_print_handle {
	char	*input;
	char	**parsed_flags;
	int		lenght;
};

void					ft_free_ptr_buff(char	**buff, int lenght);
char					ft_get_next_segment(char	*flags, char c);
char					*ft_chop_last_segment(char	*str, char c);
char					*ft_ctoa(char c);
char					*ft_utoa(unsigned int u);
char					*ft_xtoa(int x);
char					*ft_xxtoa(int xx);
struct s_print_handle	*parse_flags(char *input, va_list *flag_list);
int						interpret_handle(const struct s_print_handle *handle);
int						ft_printf(const char *str, ...);
#endif
