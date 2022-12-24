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
	if (!ptr){
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*merging(char *joined, char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		joined[j] = str2[i];
		i++;
		j++;
	}
	joined[j] = '\0';
	free(str1);
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
	char *lst_line;
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
	lst_line = ft_substr(saved, 0, ft_strlen(saved));
	free(saved);
	saved = NULL;
	return lst_line;	
}
char *update_saved(char *saved)
{
	int j = 0;
	char *hold;
	if(!saved[0])
		return NULL;
	while(saved[j])
	{
		if (saved[j] == '\n')
		{
			size_t len = ft_strlen(saved);
			hold = ft_substr(saved, j+1, len);
			free(saved);
			return hold;
		}
		j++;
	}
	return NULL;	
}

char *get_rd(char *saved,char *buffer, int fd)
{
	int rd = 1;
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
		if(!buffer[0])
			break;
		saved = ft_strjoin(saved, buffer);
		if(ft_strchr(saved, '\n') == 0)
			break;
		i++;
	}	
	free(buffer);
	return saved;
}

char *get_next_line(int fd)
{
	static char *saved;
	char *line;
	char *buffer;
	
	if(fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
		return NULL;
	buffer = malloc((BUFFER_SIZE +1) * sizeof(char));
	line = NULL;
	saved = get_rd(saved, buffer, fd);
	line = get_line(saved);
	if (!line || line[0] == '\0')
	{
		if(saved)
			free(saved);
		free(line);
		return(NULL);
	}
	saved = update_saved(saved);
	return line;
}

// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	int i = 1;
// 	check_leaks();
// 	while(line)
// 	{
// 		// red();
// 		printf("%d line :)", i);
// 		// yellow(); 
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// }

