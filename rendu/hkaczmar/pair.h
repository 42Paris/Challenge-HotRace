#pragma once

typedef struct node_s
{
	const char		*key, *value;
	struct node_s	*left, *right;
	int				disabled;		// Refer to [1]
}	node;

node	*new_node(const char *key, const char *value);
node	*get_node(const char *key, node *root);
void	insert(const char *line, const char *equal_pos, node **root);
void	delete(const char *key, node *root);

/*
 *
 * [1]: To be honest, I was too lazy to implement tree balancing, so I just
 *		decided to never delete a node from the tree, saving cycles and
 *		reallocations. Instead, nodes are marked "disabled" when they are
 *		supposed to be deleted. Meh.
 *
 */
