#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# define BUFFER_SIZE 15
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
char    *get_next_line(int fd);
#endif