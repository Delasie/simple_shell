#include "shell.h"

/**
 * _eputs - This function prints a string to the standard error output (stderr).
 * @str: The string to be printed
 *
 * Return: This function does not return a value.
 */
void _eputs(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _eputchar(str[i]);
        i++;
    }
}

/**
 * _eputchar - This function writes a character to the standard error output (stderr).
 * @c: The character to be printed
 *
 * Return: On success, it returns 1. On error, it returns -1, and sets the errno accordingly.
 */
int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(2, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}

/**
 * _putfd - This function writes a character to a specified file descriptor (fd).
 * @c: The character to be printed
 * @fd: The file descriptor to write to
 *
 * Return: On success, it returns 1. On error, it returns -1, and sets the errno accordingly.
 */
int _putfd(char c, int fd)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}

/**
 * _putsfd - This function prints a string to the specified file descriptor (fd).
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: It returns the number of characters written to the file descriptor.
 */
int _putsfd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return (0);
    while (*str)
    {
        i += _putfd(*str++, fd);
    }
    return (i);
}
