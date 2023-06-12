/* SPDX-License-Identifier: BSD-3-Clause */

#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    /* TODO: Implement nanosleep(). */
    int result = syscall(__NR_nanosleep, req, rem);
    if (result < 0)
    {
        errno = -result;
        result = -1;
    }

    return result;
}
