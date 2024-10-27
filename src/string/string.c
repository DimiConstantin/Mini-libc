// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while(source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	for (size_t i = 0; i < len; ++i)
		destination[i] = source[i];
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	size_t len1 = strlen(destination);
	size_t len2 = strlen(source);
	size_t i = len1;
	while (i < len1 + len2) {
		destination[i] = source[i - len1];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t len1 = strlen(destination);
	size_t len2 = strlen(source);
	size_t i = len1;
	while (i < len1 + len2 && len) {
		destination[i] = source[i - len1];
		i++;
		len--;
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 && *str2 && *str1 == *str2) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 && *str1 == *str2 && len) {
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
		return 0;
	return *str1 - *str2;
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
	while(*str != 0) {
		if (*str == c)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *last = NULL;
	while(*str != 0) {
		if (*str == c)
			last = str;
		str++;
	}
	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	for (int i = 0; (i < len1) && (i + len2 <= len1); ++i) {
		int ok = 1;
		for (int j = 0; j < len2; ++j)
			if (haystack[i + j] != needle[j])
				ok = 0;
		if (ok)
			return (char *)(haystack + i);
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	const char *last = NULL;
	for (int i = 0; (i < len1) && (i + len2 <= len1); ++i) {
		int ok = 1;
		for (int j = 0; j < len2; ++j)
			if (haystack[i + j] != needle[j])
				ok = 0;
		if (ok)
			last = haystack + i;
	}
	return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (size_t i = 0; i < num; ++i)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (size_t i = 0; i < num; ++i)
		dest[i] = src[i];
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *aux1 = (char *)ptr1;
	char *aux2 = (char *)ptr2;
	for (size_t i = 0; i < num; ++i) {
		if (aux1[i] > aux2[i])
			return 1;
		else if (aux1[i] < aux2[i])
			return -1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	void *start = source;
	for (size_t i = 0; i < num; ++i) {
		*(unsigned char *)source = value;
		source++;
	}
	source = start;
	return source;
}
