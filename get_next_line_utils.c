#include "get_next_line.h"

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