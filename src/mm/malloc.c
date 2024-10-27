// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (!size)
		return NULL;
	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!block)
		return NULL;
	mem_list_add(block, size);
	return block;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	if (!size)
		return NULL;
	size_t total_size = nmemb * size;
	void *block = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!block)
		return NULL;
	memset(block, 0, total_size);
	mem_list_add(block, size);
	return block;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *deleted = mem_list_find(ptr);
	munmap(deleted->start, deleted->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *node = mem_list_find(ptr);
	node->start = mremap(ptr, node->len, size, 0);
	node->len = size;
	return node->start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
	return realloc(ptr, total_size);
}
