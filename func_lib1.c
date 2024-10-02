#include "main.h"

/**
 * increase_bufer_size - increases the initially allocated space 
 * and copy the old content to it
 * @old_buffer: the old buffer parsed
 * @buffer_count: number of times the memry is being incremented
 * Return: new_buffer on success and NULL otherwise
 */
char *increase_buffer_size(char *old_buffer, int buffer_count)
{
    unsigned int i = 0;
    char *new_buffer;

    buffer_count++;
    new_buffer = malloc(BUFFER * buffer_count);
    if (new_buffer == NULL)
        return (NULL);

    while (old_buffer[i] != '\0')
    {
        new_buffer[i] = old_buffer[i];
        i++;
    }

    return (new_buffer);
}