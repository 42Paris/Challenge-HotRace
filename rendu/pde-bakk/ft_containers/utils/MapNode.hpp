/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: peerdb <peerdb@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/28 00:16:51 by peerdb        #+#    #+#                 */
/*   Updated: 2020/10/19 22:20:18 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

# include "Colours.h"

namespace ft {

	enum Col {
		BLACK,
		RED
	};

	template <typename T, class C>
	class node {
	public:
		typedef T			value_type;
		typedef	T&			reference;
		typedef const T&	const_reference;
		typedef	T*			pointer;
		typedef	const T*	const_pointer;
		typedef	C			key_compare;
		
		value_type	data;
		node		*parent;
		node		*left;
		node 	    *right;
		Col			colour;

		explicit node(value_type const& val = value_type(), Col kleur = RED) : data(val), parent(0), left(0), right(0), colour(kleur) { }
		node(const node& x) : data(x.data), parent(x.parent), left(x.left), right(x.right), colour(RED) {
		}
		~node() {}
		node&	operator=(const node& x) {
			if (this != &x) {
				this->data = x.data;
				this->parent = x.parent;
				this->left = x.left;
				this->right = x.right;
				this->colour = x.colour;
			}
			return *this;
		}
		bool	operator==(const node& other) {
			return (this->data == other.data);
		}
		bool	operator!=(const node& other) {
			return (this->data != other.data);
		}
		bool	operator>(const node& other) {
			return (this->data > other.data);
		}
		bool	operator<(const node& other) {
			return (this->data < other.data);
		}
		bool 	operator<=(const node& other) {
        	return (this->data <= other.data);
        }
        bool 	operator>=(const node& other) {
        	return (this->data >= other.data);
        }
		node*   getnext() {
//			std::cerr << "getnext gets called " << std::endl;
        	node* it(this);

        	if (it->right) {
        		it = it->right;
        		while (it->left)
        			it = it->left;
        	}
        	else {
        		node *tmp = it;
        		it = it->parent;
				while (it->left != tmp) { //it->data <= this->data)
					tmp = it;
					it = it->parent;
				}
        	}
        	return (it);
        }
        node*   getprevious() {
			setreferencenodes();
			if (this == this->first_node || this == this->last_node)
				return this->parent;
	        node* it(this);

	        if (it->left) {
		        it = it->left;
		        while (it->right)
			        it = it->right;
	        }
	        else
	        	while (it->data >= this->data)
	        		it = it->parent;
	        return (it);
        }
	private:
		void	setreferencenodes() {
			node	*tmp(this);
			while (tmp->parent)
				tmp = tmp->parent;
			this->root_node = tmp;
			while (tmp->left)
				tmp = tmp->left;
			this->first_node = tmp;
			tmp = this->root_node;
			while (tmp->right)
				tmp = tmp->right;
			this->last_node = tmp;
		}
	// ?
	node		*root_node;
	node		*first_node;
	node		*last_node;
	
	};
}


#endif
