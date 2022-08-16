#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*ret;
	int		fd1;
	int		fd2;
	size_t	i;

	fd1 = 0;
	fd2 = 0;
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{	
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 6)
	{
		ret = get_next_line(fd1);
		printf("str is %s\n", ret);
		free(ret);
		ret = get_next_line(fd2);
		printf("str is %s\n", ret);
		free(ret);
		++i;
	}
	close(fd1);
	close(fd2);
	return (0);
}