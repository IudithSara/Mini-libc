/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <string.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement lseek(). */
	int result = syscall(__NR_fstat, fd, st);
	if (result < 0) {
		errno = -result;
		result = -1;
	}
	return result;
}
