#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

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

void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void green() {
  printf("\033[0;32m");
}

void reset () {
  printf("\033[0m");
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if(s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if(s2)
	{
		while (s2[j])
			{
				str[i] = s2[j];
				i++;
				j++;
			}
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return 0;
	return (1);
}

char *get_line(char *saved)
{
	int j = 0;
	char *line;
	if(!saved || saved[0] == '\0')
		return NULL;
	while(saved[j] != '\0')
		{
			if (saved[j] == '\n')
			{
				line = ft_substr(saved, 0, j+1);
				return line;
			}
			j++;
		}
	return saved;	
}
char *update_saved(char *saved)
{
	int j = 0;
	// if(saved[0] == '\0')
	// 	return NULL;
	while(saved[j])
	{
		if (saved[j] == '\n')
		{
			size_t len = ft_strlen(saved);
			saved = ft_substr(saved, j+1, len);
			return saved;
		}
		j++;
	}
	return saved;	
}

char *get_rd(char *saved, int fd)
{
	int rd = 1;
	char *buffer;
	char *lst_line;
	buffer = malloc(BUFFER_SIZE +1);
	int i = 0;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if(rd == -1)
		{
			free(saved);
			saved = NULL;
			free(buffer);
			return NULL;
		}
		buffer[rd] = '\0';
		saved = ft_strjoin(saved, buffer);
		if(ft_strchr(saved, '\n') == 0)
			break;
		i++;
	}	
	free(buffer);
	if(rd == 0 && !buffer[0])
	{
		lst_line = get_line(saved);
		// saved = update_saved(saved);
		return lst_line;
	}
	return saved;
}

char *get_next_line(int fd)
{
	static char *saved;
	char *line;

	line = NULL;
	int j;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	saved = get_rd(saved, fd);
	j = 0;
	line = get_line(saved);
	if (!line)
		return(NULL);
	saved = update_saved(saved);
	if (!saved)
		return(NULL);
	if(line[0] == '\0')
		return NULL;
	return line;
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 1;
	while(i < 240)
	{
		red();
		printf("%d line :)", i);
		yellow(); 
		// printf("%s", line);
		printf("%s", line);
		line = get_next_line(fd);
		i++;
	}
}

