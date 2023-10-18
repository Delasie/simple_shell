#include "shell.h"

/**
 * get_history_file - Retrieves the history file path.
 * @info: The parameter structure.
 *
 * Return: An allocated string containing the history file path.
 */

char *get_history_file(info_t *info)
{
    char *buf, *dir;

    dir = _getenv(info, "HOME="); // Get the user's home directory.
    if (!dir)
        return (NULL);

    buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2)); // Allocate memory for the file path.
    if (!buf)
        return (NULL);
    buf[0] = 0;
    _strcpy(buf, dir); // Copy the home directory path.
    _strcat(buf, "/"); // Append a '/' character.
    _strcat(buf, HIST_FILE); // Append the history file name.
    return (buf);
}

/**
 * write_history - Creates a history file or appends to an existing one.
 * @info: The parameter structure.
 *
 * Return: 1 on success, -1 on failure.
 */
int write_history(info_t *info)
{
    ssize_t fd;
    char *filename = get_history_file(info); // Get the history file path.
    list_t *node = NULL;

    if (!filename)
        return (-1);

    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644); // Open or create the history file.
    free(filename);
    if (fd == -1)
        return (-1);
    for (node = info->history; node; node = node->next)
    {
        _putsfd(node->str, fd); // Write each history entry to the file.
        _putfd('\n', fd); // Append a newline character.
    }
    _putfd(BUF_FLUSH, fd); // Flush the file buffer.
    close(fd);
    return (1);
}

/**
 * read_history - Reads history from a file.
 * @info: The parameter structure.
 *
 * Return: The number of history entries read on success, 0 on failure.
 */
int read_history(info_t *info)
{
    int i, last = 0, linecount = 0;
    ssize_t fd, rdlen, fsize = 0;
    struct stat st;
    char *buf = NULL, *filename = get_history_file(info); // Get the history file path.

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY); // Open the history file for reading.
    free(filename);
    if (fd == -1)
        return (0);
    if (!fstat(fd, &st))
        fsize = st.st_size;
    if (fsize < 2)
        return (0);
    buf = malloc(sizeof(char) * (fsize + 1)); // Allocate memory for reading the file.
    if (!buf)
        return (0);
    rdlen = read(fd, buf, fsize); // Read the file into the buffer.
    buf[fsize] = 0;
    if (rdlen <= 0)
        return (free(buf), 0);
    close(fd);
    for (i = 0; i < fsize; i++)
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            build_history_list(info, buf + last, linecount++); // Create a history list entry.
            last = i + 1;
        }
    if (last != i)
        build_history_list(info, buf + last, linecount++); // Create the last history list entry.
    free(buf);
    info->histcount = linecount;
    while (info->histcount-- >= HIST_MAX)
        delete_node_at_index(&(info->history), 0); // Remove history entries beyond the limit.
    renumber_history(info); // Renumber the history entries.
    return (info->histcount);
}

/**
 * build_history_list - Adds an entry to the history linked list.
 * @info: The parameter structure.
 * @buf: The buffer containing the history entry.
 * @linecount: The history line count.
 *
 * Return: Always returns 0.
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
    list_t *node = NULL;

    if (info->history)
        node = info->history;
    add_node_end(&node, buf, linecount); // Add the history entry to the linked list.

    if (!info->history)
        info->history = node;
    return (0);
}

/**
 * renumber_history - Renumber the history linked list after changes.
 * @info: The parameter structure.
 *
 * Return: The new history count.
 */
int renumber_history(info_t *info)
{
    list_t *node = info->history;
    int i = 0;

    while (node)
    {
        node->num = i++; // Update the history entry numbers.
        node = node->next;
    }
    return (info->histcount = i);
}

