#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

int		main(void)
{
	char	*line = NULL;
	int		i = 0;
	int		res;

	int		fd = open("text2", O_RDONLY);

	while ((res = get_next_line(fd, &line)) != 0)
	{
		if (res == -1)
		{
			printf("%d -\tfd: %d | res : %d || %s\n", i++, fd, res, line);
			if (line)
				free(line);
			return (0);
		}
		printf("%d -\tfd: %d | res : %d || %s\n", i++, fd, res, line);
		free(line);
	}
	printf("%d -\tfd: %d | res : %d || %s\n", i++, fd, res, line);
	//printf("OK");
	if (line)
		free(line);
	
	//int		fds[2];
	//int		a;
	//fds[0] = open("text1", O_RDONLY);
	//fds[1] = open("text2", O_RDONLY);
	//while ((res = get_next_line(fds[i % 2], &line)) != 0)
	//{
	//	if ((i % 2) == 1)
	//		a = 1;
	//	else
	//		a = 0;
	//	if (res == -1)
	//	{
	//		printf("%d | %d (%d) %s\n", fds[a], i++, res, line);
	//		free(line);
	//		return (0);
	//	}
	//	printf("%d | %d (%d) %s\n", fds[a], i++, res, line);
	//	free(line);
	//}
	//printf("%d | %d (%d) %s\n", fds[a], i++, res, line);
	//free(line);

	//while ((res = get_next_line(0, &line)) != 0)
	//{
	//	if (res == -1)
	//    {
	//		printf("%d | %d (%d) %s\n", 0, i++, res, line);
	//        free(line);
	//        return (0);
	//    }
	//	printf("%d | %d (%d) %s\n", 0, i++, res, line);
	//	free(line);
	//}
	//printf("%d | %d (%d) %s\n", 0, i++, res, line);
	//free(line);

	//getchar();
	//char *leak = ft_strdup("Hello Leak!");
	//printf("\n\n%s\n\n", leak);
	//free(leak);

	return (0);
}
