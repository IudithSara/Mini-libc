/* SPDX-License-Identifier: BSD-3-Clause */

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	 int mode = 0;
    if ((flags & O_CREAT) != 0) {
        va_list arg;
        va_start(arg, flags);
        mode = va_arg(arg, int);
        va_end(arg);
    }

    int result = syscall(__NR_open, filename, flags, mode);
    if (result < 0) {
        errno = -result;
        result = -1;
    }
    return result;
}