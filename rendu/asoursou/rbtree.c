/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:10:29 by asoursou          #+#    #+#             */
/*   Updated: 2021/04/07 19:15:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "hotrace.h"

/*
* This implementation is based on the following book:
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest et Clifford Stein,
* Introduction to Algorithms, Chapter 13 Red-Black Trees, Cambridge (Mass.),
* MIT Press, 2009, 3rd ed
*/

static void rotate_left(t_rbtree **root, t_rbtree *x)
{
	t_rbtree *y;

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else
		*root = y;
	y->left = x;
	x->parent = y;
}

static void rotate_right(t_rbtree **root, t_rbtree *y)
{
	t_rbtree *x;

	x = y->left;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent)
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	else
		*root = x;
	x->right = y;
	y->parent = x;
}

static t_rbtree *insert_fixup_left(t_rbtree **root, t_rbtree *x)
{
	if (x->parent->parent->right && x->parent->parent->right->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		x = x->parent->parent;
		x->right->color = RB_BLACK;
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->right)
			rotate_left(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		x->parent->parent->color = RB_RED;
		rotate_right(root, x->parent->parent);
	}
	return (x);
}

static t_rbtree *insert_fixup_right(t_rbtree **root, t_rbtree *x)
{
	if (x->parent->parent->left && x->parent->parent->left->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		x = x->parent->parent;
		x->left->color = RB_BLACK;
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->left)
			rotate_right(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		x->parent->parent->color = RB_RED;
		rotate_left(root, x->parent->parent);
	}
	return (x);
}

static t_rbtree *detach_fixup_left(t_rbtree **root, t_rbtree *w, t_rbtree *x)
{
	if ((w = x->parent->right)->color == RB_RED)
	{
		w->color = RB_BLACK;
		x->parent->color = RB_RED;
		rotate_left(root, x->parent);
		w = x->parent->right;
	}
	if ((!w->left || w->left->color == RB_BLACK)
		&& (!w->right || w->right->color == RB_BLACK))
	{
		w->color = RB_RED;
		return (x->parent);
	}
	if (!w->right || w->right->color == RB_BLACK)
	{
		w->left->color = RB_BLACK;
		w->color = RB_RED;
		rotate_right(root, w);
		w = x->parent->right;
	}
	w->color = x->parent->color;
	x->parent->color = RB_BLACK;
	w->right->color = RB_BLACK;
	rotate_left(root, x->parent);
	return (*root);
}

static t_rbtree *detach_fixup_right(t_rbtree **root, t_rbtree *w, t_rbtree *x)
{
	if ((w = x->parent->left)->color == RB_RED)
	{
		w->color = RB_BLACK;
		x->parent->color = RB_RED;
		rotate_right(root, x->parent);
		w = x->parent->left;
	}
	if ((!w->right || w->right->color == RB_BLACK)
		&& (!w->left || w->left->color == RB_BLACK))
	{
		w->color = RB_RED;
		return (x->parent);
	}
	if (!w->left || w->left->color == RB_BLACK)
	{
		w->right->color = RB_BLACK;
		w->color = RB_RED;
		rotate_left(root, w);
		w = x->parent->left;
	}
	w->color = x->parent->color;
	x->parent->color = RB_BLACK;
	w->left->color = RB_BLACK;
	rotate_right(root, x->parent);
	return (*root);
}

static void detach_fixup(t_rbtree **root, t_rbtree *w, t_rbtree *x)
{
	while (x != *root && x->color == RB_BLACK)
		if (x == x->parent->left)
			x = detach_fixup_left(root, w, x);
		else
			x = detach_fixup_right(root, w, x);
	x->color = RB_BLACK;
}

static void transplant(t_rbtree **root, t_rbtree *u, t_rbtree *v)
{
	if (!u->parent)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

// Avoid NULL pointer during deletion
static t_rbtree *set_guard(t_rbtree *z, t_rbtree *guard)
{
	t_rbtree *x;

	x = z->right;
	if (!x)
	{
		x = guard;
		x->parent = z;
		x->left = NULL;
		x->right = NULL;
		x->color = RB_BLACK;
		z->right = x;
	}
	return (x);
}

// Detachs guard which is a temporary node
static void remove_guard(t_rbtree **root, t_rbtree *x, t_rbtree *g)
{
	if (x != g)
		return ;
	if (!(x = x->parent))
		*root = NULL;
	else if (x->left == g)
		x->left = NULL;
	else
		x->right = NULL;
}

static t_rbtree	*detach_case2children(t_rbtree **root, t_rbtree *z,
				t_rbtree *guard, t_rbcolor *ycolor)
{
	t_rbtree *x;
	t_rbtree *y;

	y = z->right;
	if (y)
		while (y->left)
			y = y->left;
	*ycolor = y->color;
	x = set_guard(y, guard);
	if (y->parent == z)
		x->parent = y;
	else
	{
		transplant(root, y, y->right);
		y->right = z->right;
		y->right->parent = y;
	}
	transplant(root, z, y);
	y->left = z->left;
	y->left->parent = y;
	y->color = z->color;
	return (x);
}

t_rbtree *rbtree_find(t_rbtree *r, const t_str *k)
{
	int d;

	while (r && (d = str_cmp(k, &r->key)))
		r = d < 0 ? r->left : r->right;
	return (r);
}

void rbtree_insert(t_rbtree **r, t_rbtree *e)
{
	int			d;
	t_rbtree	*x;
	t_rbtree	*y;

	x = *r;
	y = NULL;
	while (x)
	{
		y = x;
		d = str_cmp(&e->key, &x->key);
		x = d < 0 ? x->left : x->right;
	}
	if (!(e->parent = y))
		*r = e;
	else if (d < 0)
		y->left = e;
	else
		y->right = e;
	while (e != *r && e->parent->color == RB_RED)
		if (e->parent == e->parent->parent->left)
			e = insert_fixup_left(r, e);
		else
			e = insert_fixup_right(r, e);
	(*r)->color = RB_BLACK;
}

t_rbtree *rbtree_new(const t_str *k, const t_str *v)
{
	char		*b;
	t_rbtree	*r;

	// heap: [STR_KEY STR_VALUE RBTREE_STRUCT] (single allocation for pair)
	b = malloc(k->n + v->n + 2 + sizeof(t_rbtree));
	if (!b)
		return (NULL);
	r = (t_rbtree*)(b + k->n + v->n + 2);
	r->parent = NULL;
	r->left = NULL;
	r->right = NULL;
	r->color = RB_RED;
	str_init(&r->key, memcpy(b, k->s, k->n + 1), k->n);
	str_init(&r->value, memcpy(b + k->n + 1, v->s, v->n + 1), v->n);
	return (r);
}

void rbtree_remove(t_rbtree **root, t_rbtree *z)
{
	t_rbtree	guard;
	t_rbtree	*x;
	t_rbcolor	ycolor;

	ycolor = z->color;
	if (!z->left)
		transplant(root, z, (x = set_guard(z, &guard)));
	else if (!z->right)
		transplant(root, z, (x = z->left));
	else
		x = detach_case2children(root, z, &guard, &ycolor);
	if (ycolor == RB_BLACK && *root != &guard)
		detach_fixup(root, NULL, x);
	remove_guard(root, x, &guard);
	free((void*)z->key.s);
}
