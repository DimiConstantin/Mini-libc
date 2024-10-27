#ifndef	__STRING_H__
#define	__STRING_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec
{
    long long tv_sec;
    long long tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *duration, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
