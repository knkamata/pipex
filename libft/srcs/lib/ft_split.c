/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:48:33 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/07 13:59:07 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_arrclear(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	ft_strcnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0)
			|| (s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_strset(char const *s, char c, size_t *p)
{
	size_t	bgn;
	size_t	len;

	bgn = *p;
	len = 0;
	while (s[*p] && s[*p] != c)
	{
		len++;
		*p += 1;
	}
	return (ft_substr(s, bgn, len));
}

static char	*ft_strsplit(char const *s, char c, size_t *p)
{
	while (s[*p])
	{
		if (s[*p] != c && *p == 0)
			break ;
		if (s[*p] == c && s[*p + 1] != c && s[*p + 1] != '\0')
		{
			*p += 1;
			break ;
		}
		*p += 1;
	}
	return (ft_strset(s, c, p));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	p;
	size_t	strcnt;
	char	**dst;

	if (!s)
		return (NULL);
	strcnt = ft_strcnt(s, c);
	dst = (char **)malloc(sizeof(char *) * (strcnt + 1));
	if (!dst)
		return (NULL);
	i = 0;
	p = 0;
	while (i < strcnt)
	{
		dst[i] = ft_strsplit(s, c, &p);
		if (!dst[i])
		{
			ft_arrclear(dst);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
