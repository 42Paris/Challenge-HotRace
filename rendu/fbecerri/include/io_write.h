#ifndef IO_WRITE_H

# define IO_WRITE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 4096

typedef struct  s_write
{
    char        buffer[BUFFER_SIZE];
    int         index;
    int         nb_write;
}               t_write;

void    io_flush(t_write *output)
{
    if (output->index > 0)
        write(1, output->buffer, output->index);
    output->index = 0;
}

void    io_write(t_write *output, char *str, int size)
{
    int        space;

    space = BUFFER_SIZE - output->index;
    while (space < size)
    {
        memcpy(output->buffer + output->index, str, space);
        output->index += space;
        io_flush(output);
        str += space;
        size -= space;
        output->nb_write += space;
        space = BUFFER_SIZE;
    }
    memcpy(output->buffer + output->index, str, size);
    output->nb_write += size;
    output->index += size;
}

void    io_putchar(t_write *output, char c)
{
    io_write(output, &c, 1);
}

#endif