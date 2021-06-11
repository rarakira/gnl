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

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

#endif
