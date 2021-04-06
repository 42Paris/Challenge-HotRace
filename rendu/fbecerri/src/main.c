#include "hash.h"
#include "hotRace.h"
#include "ft_string.h"
#include "io_read.h"
#include "io_write.h"

int     test = 0;

int     main(void) {
    t_io_read   *r;
    t_string    s1;
    t_string    s2;
    t_mode      m;
    t_hashtable *table;
    int         i = 0;
    t_write     w;

    test = 0;
    w.index = 0;
    w.nb_write = 0;
    r = init_reader(4096, 0);
    io_read_file(&r);
    table = create_hashtable(4096);
    while ((m = read_line(&s1, &s2, r)) != (t_mode)end) {
        if (m == (t_mode)add) {
            t_entry *ent = insert_hashtable(&table, create_entry(s1));
            if (ent)
                ent->data = s2;
        } else if (m == (t_mode)research) {
            print_string(&w, s1);
            io_write(&w, ": ", 2);
            t_entry *ent = hashtable_get(table, s1);
            if (ent == NULL)
                io_write(&w, "Not found\n", 10);
            else {
                print_string(&w, ent->data);
                io_write(&w, "\n", 1);
            }
        } else {
            hashtable_delete(table, s1);
        }
        i++;
    }
    io_flush(&w);
    free(r);
    free(table);
    printf("time = %d\n", test);
    return (0);
}