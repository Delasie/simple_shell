#include "shell.h"

/**
 * _memset - This function fills the memory with the constant byte
 * @s: this function represents the pointer right to the memory area
 * @b: this represents the byte that is to fill *s with
 * @n: This represents the amount of bytes that is to be filled
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
 * ffree - This function frees up  a string of alot of strings
 * @pp: this represents the string of strings
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
 * _realloc - this function also reallocates the block of memory
 * @ptr: this function represents the pointer to the previous mal located block
 * @old_size: this displays the byte size of the previous block
 * @new_size: this displays the byte size of a new block
 *
 * Return: pointer to the  o block name.
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
