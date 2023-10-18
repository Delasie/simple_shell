#include "shell.h"

/**
 * _memset - This function fills the memory with the same or constant byte
 * @s: This represents the pointer showing to the memory area
 * @b: represents the byte that is used to to fill s with
 * @n: represents the amount of bytes that is to be filled
 * Return: (s) represents a pointer to a memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - this function frees up  a string of the strings
 * @pp: this represents the string of the strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - This function reallocates the block of a memory
 * @ptr: represents the pointer to the previous mal located block
 * @old_size: displays the byte size of the previous block
 * @new_size: displays the byte size of the new block
 *
 * Return: pointer to da old block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
