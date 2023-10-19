#include "shell.h"

/**
 * interactive_mode - Checks if the shell is in interactive mode.
 * @info: The address of the structure.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive_mode(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if the given character is a delimiter.
 * @c: The character to be checked.
 * @delim: The delimiter string.
 * Return: 1 if 'c' is a delimiter, otherwise return 0.
 */
int is_delimiter(char c, char *delim)
{
    while (*delim)
    {
        if (*delim++ == c)
            return (1);
    }
    return (0);
}

/**
 * is_alpha - Checks if the given character is an alphabetic character.
 * @c: The character to be checked.
 * Return: 1 if 'c' is an alphabetic character, otherwise return 0.
 */
int is_alpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * string_to_integer - Transforms the given string into an integer.
 * @s: The string to be transformed.
 * Return: If no numbers in string return 0, otherwise returns the converted number.
 */
int string_to_integer(char *s)
{
    int j, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (j = 0; s[j] != '\0' && flag != 2; j++)
    {
        if (s[j] == '-')
            sign *= -1;

        if (s[j] >= '0' && s[j] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[j] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}
