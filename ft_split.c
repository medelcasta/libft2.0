/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedel-r <amedel-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:27:56 by amedel-r          #+#    #+#             */
/*   Updated: 2024/11/07 17:50:28 by amedel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**set_substrs(char const *s, char **str_cont, char c,
		size_t token_count)
{
	size_t	substr_count;
	size_t	subs_str_len;
	char	*next_t;

	substr_count = 0;
	while (*s == c)
		++s;
	while (substr_count < token_count)
	{
		if (*s && *s != c)
		{
			next_t = ft_strchr(s, c);
			subs_str_len = (next_t - s);
			if (!next_t)
				subs_str_len = (ft_strchr(s, '\0') - s);
			str_cont[substr_count] = ft_calloc(subs_str_len + 1, sizeof(char));
			if (!str_cont[substr_count])
				return (NULL);
			ft_strlcpy(str_cont[substr_count], s, subs_str_len + 1);
			s = next_t;
			++substr_count;
		}
		++s;
	}
	return (str_cont);
}

static size_t	count_tokens(char const *s, char c)
{
	size_t	counter;
	int		inside_token;

	counter = 0;
	inside_token = 0;
	while (*s)
	{
		if (*s != c && !inside_token)
		{
			inside_token = 1;
			++counter;
		}
		else if (*s == c)
			inside_token = 0;
		++s;
	}
	return (counter);
}

static void	ft_freemtx(void **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		free(mtx[i++]);
	free(mtx);
}

char	**ft_split(char const *s, char c)
{
	size_t	c_count;
	char	**str_cont;

	c_count = count_tokens(s, c);
	str_cont = malloc(sizeof(char *) * (c_count + 1));
	if (!str_cont)
		return (NULL);
	if (!set_substrs(s, str_cont, c, c_count))
	{
		ft_freemtx((void **)str_cont);
		return (NULL);
	}
	str_cont[c_count] = NULL;
	return (str_cont);
}
