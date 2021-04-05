#ifndef FT_STRING_H

# define FT_STRING_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "io_write.h"

typedef struct  s_string {
    int     index;
    size_t  len;
    char    *buffer;
}               t_string;

t_string    create_string(char *buf, size_t len) {
    t_string s;

    s.index = 0;
    s.len = len;
    s.buffer = buf;
    return (s);
}

t_string    join_string(t_string s1, t_string s2) {
    t_string s;

    s.index = 0;
    s.len = s1.len + s2.len;
    s.buffer = (char *)malloc(sizeof(char) * s.len);
    memcpy(s.buffer, s1.buffer, s1.len);
    memcpy(s.buffer + s1.len, s2.buffer, s2.len);
    return (s);
}

void    print_string(t_write *r, t_string s1) {
    io_write(r, s1.buffer, s1.len);
}

bool    ft_strcmp(t_string s1, t_string s2) {
    size_t i;

    i = 0;
    if (s1.len != s2.len) {
        return (false);
    }
    while (i < s1.len) {
        if (s1.buffer[i] != s2.buffer[i])
            return (false);
        i++;
    }
    return (true);
}

#endif