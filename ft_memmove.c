/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:27:50 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 17:52:18 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (dest == src || n == 0)
		return (dest);
	if (src < dest && dest < src + n)
	{
		temp_dest = (unsigned char *)dest + n;
		temp_src = (unsigned char *)src + n;
		while (n--)
			*(--temp_dest) = *(--temp_src);
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
