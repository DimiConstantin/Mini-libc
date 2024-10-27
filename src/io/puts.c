#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <internal/io.h>

int puts(char *buf)
{
    int len = strlen(buf);
    int bytes = write(1, buf, len);
    if (bytes < 0)
        return -1;
    bytes = write(1, "\n", 1);
    if (bytes < 0)
        return -1;
    return 1;
}
