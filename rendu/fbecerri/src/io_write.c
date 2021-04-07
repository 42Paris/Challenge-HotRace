/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:29:13 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:29:15 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_write.h"

void    io_flush(t_write *output)
{
    if (output->index > 0)
        write(1, output->buffer, output->index);
    output->index = 0;
}

void    io_write(t_write *output, char *str, int size)
{
    int        space;

    space = BUFFER_SIZE_W - output->index;
    while (space < size)
    {
        memcpy(output->buffer + output->index, str, space);
        output->index += space;
        io_flush(output);
        str += space;
        size -= space;
        output->nb_write += space;
        space = BUFFER_SIZE_W;
    }
    memcpy(output->buffer + output->index, str, size);
    output->nb_write += size;
    output->index += size;
}

void    io_putchar(t_write *output, char c)
{
    io_write(output, &c, 1);
}
