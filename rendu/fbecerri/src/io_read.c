/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:29:03 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:29:05 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_read.h"

t_io_read       *init_reader(size_t size, int fd) {
    t_io_read *r;

    r = (t_io_read *)malloc(sizeof(t_io_read) + sizeof(char) * size);
    r->index = 0;
    r->size = 0;
    r->size_max = size;
    r->fd = fd;
    return (r);
}

int     io_read_file(t_io_read **r1) {
    ssize_t     nb_read;
    int         index;
    t_io_read   *r;

    r = *r1;
    index = 0;
    while ((nb_read = read(r->fd, r->buffer + index, r->size_max - index)) > 0) {
        if (nb_read == (ssize_t)r->size_max - index) {
            r->size_max *= 2;
            r = (t_io_read *)realloc(r, sizeof(t_io_read) + sizeof(char) * r->size_max);
        }
        index += nb_read;
    }
    r->size = index;
    *r1 = r;
    return (index);
}

int     read_line(t_string *s1, t_string *s2, t_io_read *r) {
    size_t  index_start;
    size_t  index_eq;
    size_t  len;
    t_mode  mode;

    if (r->index >= r->size)
        return ((t_mode)end);
    index_eq = 0;
    index_start = r->index;
    len = 0;
    while (r->index < r->size && r->buffer[r->index] != '\n') {
        if (r->buffer[r->index] == '=' && index_eq == 0) {
            index_eq = r->index;
        }
        r->index++;
        len++;
    }
    r->index++;
    if (r->buffer[index_start] == '!') {
        *s1 = create_string(r->buffer + index_start + 1, len - 1);
        mode = del;
    } else if (index_eq != 0) {
        *s1 = create_string(r->buffer + index_start, index_eq - index_start);
        *s2 = create_string(r->buffer + index_eq + 1, len - (index_eq - index_start) - 1);
        mode = add;
    } else {
        *s1 = create_string(r->buffer + index_start, len);
        mode = research;
    }
    return (mode);
}
