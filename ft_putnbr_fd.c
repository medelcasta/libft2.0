/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:56:16 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 20:56:25 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = (unsigned int)n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		un = (unsigned int)n;
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putchar_fd(un % 10 + '0', fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}
