#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define DEFAULT_BS 20
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE DEFAULT_BS
# elif BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE DEFAULT_BS
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	size_t			read_res;
}	t_list;

int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
