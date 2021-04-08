#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	hash(const char *key)
{
	unsigned int	hash = 5031;

	while (*key)
		hash = hash * 101 + *key++;

	return (hash % 16777213);
}

int				main(void)
{
	char		**tab = (char **)calloc(16777213, sizeof(char *));
	char		*line = NULL;
	size_t		size = 0;
	char		*sep;
	int			ret;

	while ((ret = getline(&line, &size, stdin)) != -1)
	{
		line[ret - 1] = '\0';
		sep = strchr(line, '=');
		if (sep)
		{
			sep[0] = '\0';
			if (!tab[hash(line)])
				tab[hash(line)] = strdup(sep + 1);
		}
		else if (line[0] == '!')
			tab[hash(line + 1)] = NULL;
		else
		{
			if (tab[hash(line)])
				printf("%s\n", tab[hash(line)]);
			else
				printf("%s: Not found\n", line);
		}
	}
	return (0);
}
