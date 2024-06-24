#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h> 

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("43_no_nl", O_RDWR);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		printf("\n%d", strcmp(line, "0123456789012345678901234567890123456789012"));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
