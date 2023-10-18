#include "shell.h"

/**
 * _strncpy - Copies a string with a specified length.
 * @dest: The destination string to copy to.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 * 
 * Returns: The concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return s;
}

/**
 * _strncat - Concatenates two strings with a specified length.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 * 
 * Returns: The concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return s;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 * 
 * Returns: A pointer to the memory area 's' where 'c' is found, or NULL if 'c' is not found.
 */
char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
            return s;
    } while (*s++ != '\0');

    return NULL;
}