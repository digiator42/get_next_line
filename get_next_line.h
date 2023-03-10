/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:30:08 by ahassan           #+#    #+#             */
/*   Updated: 2022/12/25 14:31:28 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
char	*merging(char *joined, char *str1, char *str2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *c);
char	*get_next_line(int fd);
#endif