/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <string.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int result = syscall(__NR_stat, path, buf);
	if (result < 0) {
		errno = -result;
		result = -1;
	}
	return result;
}
