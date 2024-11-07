/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:27:46 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 19:03:13 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		++temp_s1;
		++temp_s2;
	}
	return (0);
}
