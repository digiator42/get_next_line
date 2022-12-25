/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:29:52 by ahassan           #+#    #+#             */
/*   Updated: 2022/12/25 14:38:41 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c)
	{
		while (c[i] != '\0')
			i++;
	}
	else
		return (0);
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char *saved, char *buffer)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!saved)
		saved = (char *)ft_calloc(sizeof(char), 1);
	if (!saved || !buffer)
		return (NULL);
	joined = (char *)malloc((ft_strlen(saved) + ft_strlen(buffer) + 1));
	if (!joined)
		return (NULL);
	while (saved[i])
		joined[j++] = saved[i++];
	i = 0;
	while (buffer[i])
		joined[j++] = buffer[i++];
	joined[j] = '\0';
	free(saved);
	return (joined);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < slen && len > i)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
