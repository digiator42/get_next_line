#include "get_next_line.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (0);
	return (1);
}

char	*get_line(char *saved)
{
	int		j;
	char	*line;
	char	*lst_line;

	j = 0;
	if (!saved || saved[0] == '\0')
		return (NULL);
	while (saved[j] != '\0')
	{
		if (saved[j] == '\n')
		{
			line = ft_substr(saved, 0, j + 1);
			return (line);
		}
		j++;
	}
	lst_line = ft_substr(saved, 0, ft_strlen(saved));
	free(saved);
	saved = NULL;
	return (lst_line);
}
char	*update_saved(char *saved)
{
	int		j;
	char	*hold;
	size_t	len;

	j = 0;
	if (!saved[0])
		return (NULL);
	while (saved[j])
	{
		if (saved[j] == '\n')
		{
			len = ft_strlen(saved);
			hold = ft_substr(saved, j + 1, len);
			free(saved);
			return (hold);
		}
		j++;
	}
	return (NULL);
}

char	*get_rd(char *saved, int fd)
{
	int		rd;
	int		i;
	char	*buffer;

	rd = 1;
	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(saved);
			saved = NULL;
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (!buffer[0])
			break ;
		saved = ft_strjoin(saved, buffer);
		if (ft_strchr(saved, '\n') == 0)
			break ;
		i++;
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
		return (NULL);
	line = NULL;
	saved = get_rd(saved, fd);
	line = get_line(saved);
	if (!line || line[0] == '\0')
	{
		if (saved)
			free(saved);
		free(line);
		return (NULL);
	}
	saved = update_saved(saved);
	return (line);
}

// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	int i = 1;
// 	while(line)
// 	{
// 		printf("%d line :)", i);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// }
