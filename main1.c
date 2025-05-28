#include <fcntl.h>    // open
#include <unistd.h>   // close
#include <stdio.h>    // printf, perror
#include <stdlib.h>   // free
#include "get_next_line.h"

int main(int ac, char **av)
{
    int     fd;
    char    *line;

    if (ac != 2)
    {
        printf("Usage: %s <filename>\n", av[0]);
        return (1);
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}

