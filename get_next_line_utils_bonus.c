#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if(c){
	while (c[i] != '\0')
		i++;
	}
	else
	 return 0;
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
	if (!ptr){
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*merging(char *joined, char *saved, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (saved[i])
	{
		joined[i] = saved[i];
		i++;
		j++;
	}
	i = 0;
	while (buffer[i])
	{
		joined[j] = buffer[i];
		i++;
		j++;
	}
	joined[j] = '\0';
	free(saved);
	return (joined);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined;

	if (!str1)
		str1 = (char *)ft_calloc(sizeof(char), 1);
	if (!str1 || !str2)
		return (NULL);
	joined = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!joined)
		return (NULL);
	joined = merging(joined, str1, str2);
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