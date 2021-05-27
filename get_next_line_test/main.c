#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

int		main(void)
{
	char	*line;
	int		i = 0;
	int		res;

	int		fd = open("text1", O_RDONLY);

	while ((res = get_next_line(fd, &line)) != 0)
	{
		if (res == -1)
        {
			printf("%d (%d) %s\n", i++, res, line);
            free(line);
            return (0);
        }
		printf("%d (%d) %s\n", i++, res, line);
		free(line);
	}
	printf("%d (%d) %s\n", i++, res, line);
	free(line);
	
	//int		fds[2];
	//fds[0] = open("text1", O_RDONLY);
	//fds[1] = open("text2", O_RDONLY);
	//while (res = get_next_line(fds[i % 2], &line))
	//{
	//	printf("%d (%d) %s\n", i++, res, line);
	//	free(line);
	//}
	//printf("%d (%d) %s\n", i++, res, line);
	//free(line);

	return (0);
}
