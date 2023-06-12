/* SPDX-License-Identifier: BSD-3-Clause */

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		return NULL;
	}
	if (mem_list_add(ptr, size) != 0)
	{
		munmap(ptr, size);
		return NULL;
	}
	
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		return NULL;
	}

	if (mem_list_add(ptr, nmemb * size) != 0)
	{
		munmap(ptr, nmemb * size);
		return NULL;
	}

	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
	{
		return;
	}
	mem_list_del(ptr);
	munmap(ptr, mem_list_find(ptr)->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_ptr == MAP_FAILED)
	{
		return NULL;
	}

	if (mem_list_add(new_ptr, size) != 0)
	{
		munmap(new_ptr, size);
		return NULL;
	}

	memcpy(new_ptr, ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
	munmap(ptr, mem_list_find(ptr)->len);
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t new_size = nmemb * size;
	void *new_ptr = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_ptr == MAP_FAILED)
	{
		return NULL;
	}
	
	if (mem_list_add(new_ptr, new_size) != 0)
	{
		munmap(new_ptr, new_size);
		return NULL;
	}

	memcpy(new_ptr, ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
	munmap(ptr, mem_list_find(ptr)->len);
	return new_ptr;
}

