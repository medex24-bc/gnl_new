#include "get_next_line.h"

char *get_next_line(int fd)
{
	// return (la string terminé par un '\n')
	(void)fd;
	return ("");
}

int main(void)
{
	int fd;
	char buf[BUFFER_SIZE];
	ssize_t read_byte = 0;

	fd = open("./file.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	read_byte = read(fd, buf, BUFFER_SIZE);
	


	return (0);
}
