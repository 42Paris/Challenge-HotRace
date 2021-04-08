#include "hotrace.h"
#include <sys/time.h>

t_dict **g_dict;

int	main()
{
	unsigned	hash;
	char		*line = 0;
	char		*value;
	size_t		max = 0;
	ssize_t		ret;

	g_dict = calloc(HASHSIZE, sizeof(t_dict*));
	while ((ret = getline(&line, &max, stdin)) > 0)
	{
		if (line[ret - 1] == '\n')
			line[ret - 1] = 0;
		else
			line[ret] = 0;
		if (*line == '!')
			remove_dict(line + 1);
		else
		{
			hash = get_hash_and_value(line, &value);
			if (value)
				put_dict(line, value, hash);
			else
				print_dict_entry(line, hash);
		}
		line = 0;
		max = 0;
	}
}
