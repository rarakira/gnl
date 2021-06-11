#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	clean_up(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	*str1 = NULL;
	*str2 = NULL;
	return (-1);
}

int	eof_line(char **src, char **buf, char **dest)
{	
	free(*buf);
	*dest = ft_strdup(*src);
	free(*src);
	*buf = NULL;
	*src = NULL;
	if (*dest == NULL)
		return (-1);
	return (0);
}

int	get_line(char **src, char **dest)
{
	char	*tmp;
	char	*sep;

	sep = ft_strchr(*src, '\n');
	*sep = '\0';
	*dest = ft_strdup(*src);
	tmp = ft_substr(++sep, 0, BUFFER_SIZE);
	if (tmp == NULL || *dest == NULL)
	{
		free(tmp);
		tmp = NULL;
		return (clean_up(src, dest));
	}
	free(*src);
	*src = tmp;
	return (1);
}

size_t	has_new_line(char *str)
{
	if (!str)
		return (0);
	return (ft_strchr(str, '\n') != NULL);
}

int	get_next_line(int fd, char **line)
{
	static char		*rem = 0;
	ssize_t			read_res;
	char			*buf;
	char			*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_res = 1;
	if (fd < 0 || !line || !buf)
		return (clean_up(&buf, &rem));
	while (!has_new_line(rem) && read_res > 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		buf[read_res] = '\0';
		tmp = ft_strjoin(rem, buf);
		if (!tmp)
			return (clean_up(&buf, &rem));
		free(rem);
		rem = tmp;
		if (read_res < BUFFER_SIZE)
			read_res = read(fd, buf, BUFFER_SIZE);
	}
	if (read_res < 0)
		return (clean_up(&buf, &rem));
	if (has_new_line(rem))
	{
		free(buf);
		buf = NULL;
		return (get_line(&rem, line));
	}
	return (eof_line(&rem, &buf, line));
}
