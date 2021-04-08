#include "pair.h"
#include "inneclud.h"
#include <malloc.h>

/*
** Will a simple binary search tree outrun the hashtables some students already
** turned in? We'll have to see :)
**
** I didn't want to use a hashtable because of collisions and the big memory
** footprint it entails. Given that the subject doesn't give clear boundaries on how
** long a key is allowed to be, or how big the sample size will be at a maximum, I
** believe it would be very hard to provide a working solution with a simple
** hash table.
**
** It is true, double hashing is a thing, but I'm more interested to see if a
** simple binary search tree can perform well in this challenge.
**
*/

/*
** !!!! Keep in mind the rush says we shouldn't care about memory management,
** so don't expect this code to be clean! !!!!
*/

int main(void)
{
	node	*root = 0;
	char	*line = 0;
	size_t	len = 0;
	ssize_t	rd_s;

	mallopt(M_CHECK_ACTION, 0);
	while ((rd_s = getdelim(&line, &len, '\n', stdin)) != -1)
	{
		char	*equal_pos;

		line[rd_s - 1] = 0;
		if (*line == '!')
			delete(line + 1, root);
		else if ((equal_pos = strchr(line, '=')))
			insert(line, equal_pos, &root);
		else
		{
			node *n;

			n = get_node(line, root);
			if (n)
				printf("%s\n", n->value);
			else
				printf("%s: Not found\n", line);
		}
	}
}
