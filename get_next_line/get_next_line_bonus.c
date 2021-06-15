#include "get_next_line_bonus.h"

int	clean_up(char **str, t_list *current, t_list **start)
{
	t_list	*tmp;

	tmp = *start;
	free(*str);
	*str = NULL;
	if (current == NULL)
		return (-1);
	if (tmp == current)
		*start = current->next;
	else
	{
		while (tmp->next != current)
			tmp = tmp->next;
	}
	free(*str);
	if (tmp->next)
		tmp->next = tmp->next->next;
	free(current->rem);
	free(current);
	return (-1);
}

char	*has_new_line(char **str)
{
	size_t			i;

	i = 0;
	if (*str == NULL)
		return (0);
	while (*(*str + i) != '\0')
	{
		if (*(*str + i) == '\n')
			return ((char *)(*str + i));
		i++;
	}
	return (NULL);
}

int	get_line(t_list *current, char **dest, t_list **start)
{
	char	*tmp;
	char	*sep;

	sep = has_new_line(&current->rem);
	if (!sep)
	{
		*dest = ft_strdup(current->rem);
		clean_up(&current->rem, current, start);
		if (*dest == NULL)
			return (-1);
		return (0);
	}
	*sep = '\0';
	*dest = ft_strdup(current->rem);
	tmp = ft_strdup(++sep);
	if (tmp == NULL || *dest == NULL)
	{
		free(tmp);
		return (clean_up(dest, current, start));
	}
	free(current->rem);
	current->rem = tmp;
	return (1);
}

t_list	*get_current(t_list	**start, int fd)
{
	t_list	*tmp;

	tmp = *start;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->fd = fd;
		tmp->next = *start;
		*start = tmp;
		tmp->rem = (char *)malloc(sizeof(char));
		if (tmp->rem)
			tmp->rem[0] = 0;
	}
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*start = NULL;
	t_list			*current;
	ssize_t			read_res;
	char			*buf;
	char			*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buf)
		return (clean_up(&buf, NULL, &start));
	current = get_current(&start, fd);
	read_res = 1;
	while (!has_new_line(&current->rem) && read_res > 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 0)
			return (clean_up(&buf, current, &start));
		buf[read_res] = '\0';
		tmp = ft_strjoin(current->rem, buf);
		if (!tmp)
			return (-1);
		free(current->rem);
		current->rem = tmp;
	}
	free(buf);
	return (get_line(current, line, &start));
}
