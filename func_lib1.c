#include "main.h"

/* increases the initially allocated space and copy the old content to it */
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