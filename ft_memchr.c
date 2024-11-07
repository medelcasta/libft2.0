/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:27:44 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 19:02:00 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp_s;
	unsigned char		temp_c;

	temp_s = (const unsigned char *)s;
	temp_c = (unsigned char)c;
	while (n--)
	{
		if (*temp_s == temp_c)
			return ((void *)temp_s);
		++temp_s;
	}
	return (NULL);
}
