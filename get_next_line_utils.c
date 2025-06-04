/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:17:37 by ocviller          #+#    #+#             */
/*   Updated: 2025/06/04 13:35:55 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	srclen = ft_strlen(s1);
	destlen = ft_strlen(s2);
	i = 0;
	join = malloc(sizeof(char) * (srclen + destlen + 1));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[srclen + i] = s2[i];
		i++;
	}
	join[srclen + i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		srclen;
	char	*dest;

	i = 0;
	srclen = ft_strlen(s);
	dest = malloc(sizeof(char) * (srclen + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;
	size_t	slen;
	size_t	real_len;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		real_len = slen - start;
	else
		real_len = len;
	new = malloc(sizeof(char) * (real_len + 1));
	if (!new)
		return (NULL);
	while (i < len && start < slen)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
