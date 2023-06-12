/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include "puts.h"
#include <stdio.h>
#include <string.h>

int puts(const char *str) {
    size_t len = strlen(str);
    write(1, str, len);
    write(1, "\n", 1);
    return (int)len + 1;
}