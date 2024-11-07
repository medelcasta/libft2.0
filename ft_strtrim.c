/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:28:22 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 19:12:12 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char const *set, char const c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

static char	*set_trim(char const *s1, char *trimmed, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (s1[i] && i <= end)
		trimmed[j++] = s1[i++];
	trimmed[j] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		len;

	len = ft_strlen(s1);
	start = 0;
	while (checkset(set, s1[start]))
		++start;
	end = len - 1;
	if (start == len)
		return (ft_strdup(""));
	while (checkset(set, s1[end]))
		--end;
	len = end - start + 2;
	trimmed = malloc(len * sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed[len - 1] = '\0';
	return (set_trim(s1, trimmed, start, end));
}
