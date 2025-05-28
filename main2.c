#include <stdio.h>

int main()
{
	char *str;
	int fd;

	str = NULL;
	fd = open("./test2.txt", O_RDONLY );
	if(fd == -1)
		printf("open error");
	str = get_next_line(fd);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return 0;
}
