/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    /* TODO: Implement sleep(). */

    return nanosleep(&((struct timespec){.tv_sec = seconds, .tv_nsec = 0}), NULL);
}
