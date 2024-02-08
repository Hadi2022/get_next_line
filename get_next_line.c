#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	byte;
	char		c;
	char		*buffer;
	int	i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 1000000);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		buffer[i++] = c;
		if (c == '\n' || c == '\0')
		{
			break ;
		}
		byte = read(fd, &c, BUFFER_SIZE);
	}
	if (byte == 0 || byte < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}


int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
    }
    return (0);
}

