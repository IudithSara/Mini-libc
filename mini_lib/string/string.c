/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	
	 size_t i = 0;

    for (; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    destination[i] = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	 size_t i = 0;

    for (; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    for (; i < len; i++) {
        destination[i] = '\0';
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	  size_t dest_len = strlen(destination);
    size_t i = 0;

    for (; source[i] != '\0'; i++) {
        destination[dest_len + i] = source[i];
    }

    destination[dest_len + i] = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	 size_t dest_len = strlen(destination);
    size_t i = 0;

    for (; i < len && source[i] != '\0'; i++) {
        destination[dest_len + i] = source[i];
    }

    destination[dest_len + i] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	   size_t i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }

    return str1[i] - str2[i];
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;

    while (i < len && str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }

    if (i == len) {
        return 0;
    }

    return str1[i] - str2[i];
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	size_t i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            return (char *) &str[i];
        }

        i++;
    }

    if (c == '\0') {
        return (char *) &str[i];
    }

    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	size_t i = strlen(str);

    while (i > 0) {
        i--;

        if (str[i] == c) {
            return (char *) &str[i];
        }
    }

    if (c == '\0') {
        return (char *) &str[i];
    }

    return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	  size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    if (str2_len == 0) {
        return (char *) str1;
    }

    for (size_t i = 0; i <= str1_len - str2_len; i++) {
        if (memcmp(&str1[i], str2, str2_len) == 0) {
            return (char *) &str1[i];
        }
    }

    return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    if (len2 > len1) {
        return NULL;
    }

    const char *p = str1 + len1 - len2;
    while (p >= str1) {
        if (strncmp(p, str2, len2) == 0) {
            return (char *)p;
        }
        p--;
    }

    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char *dest = (char *)destination;
    const char *src = (const char *)source;
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	char *dest = (char *)destination;
    const char *src = (const char *)source;
    if (destination < source) {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = num; i > 0; i--) {
            dest[i-1] = src[i-1];
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	  const char *p1 = (const char *)ptr1;
    const char *p2 = (const char *)ptr2;
    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	 char *s = (char *)source;
    for (size_t i = 0; i < num; i++) {
        s[i] = (char)value;
    }
    return source;
}