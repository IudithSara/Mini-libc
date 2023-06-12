/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	off_t result = syscall(__NR_lseek, fd, offset, whence);

	 if (result == -1)
    {
        // set errno only if the system call failed
        errno = errno;
    }

	return result;
}
