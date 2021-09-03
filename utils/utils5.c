/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:07:24 by nrubin            #+#    #+#             */
/*   Updated: 2021/09/03 14:34:47 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Special putchar for chars when width is zero and c is zero
void	ft_zero_putchar(char c, t_list *flags)
{
	flags->width += 1;
	write(1, &c, 1);
}
