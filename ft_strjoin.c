/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:28:03 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 19:04:26 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(sizeof(char) * len);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strlcat(joined, s1, len);
	ft_strlcat(joined, s2, len);
	return (joined);
}
