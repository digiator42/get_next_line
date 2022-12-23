#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>



#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);
char *get_next_line(int fd);
void check_leaks();
#endif