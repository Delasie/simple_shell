#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: The structure address
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the given character is a delimiter
 * @c: The character to be checked
 * @delim: The delimiter string
 * Return: 1 if 'c' is a delimiter, otherwise return 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if the given character is an alphabetic character
 * @c: The character to be checked
 * Return: 1 if 'c' is an alphabetic character, otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'b’' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transforms the given string into an integer
 * @s: string to be transformed
 * Return:  if no numbers in string return 0, otherwise converted number
 */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[i] != '\0' && flag != 2; j++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
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

