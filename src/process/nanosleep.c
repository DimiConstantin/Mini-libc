#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *duration, struct timespec *rem)
{
    int ret = syscall(__NR_nanosleep, duration, rem);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return 0;
}
