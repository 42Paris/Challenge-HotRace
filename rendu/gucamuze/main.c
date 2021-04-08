/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:31:01 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 13:26:22 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	get_sign_index(char *str, int *index) 
{
	int n;

	n = 0;
	while (str[n]) {
		if (str[n] == '=') {
			*index = n;
			return (1);
		}
		n++;
	}
	return (0);
}

int	main(void)
{
	char 	str[512];
	// clock_t begin	= clock();
	t_HT	*table	= create_table();
	
	while (1) {
		// clock_t w_start = clock();
		if (fgets(str, 512, stdin)) {
			str[strlen(str) - 1] = 0;
			if (str[0] == '!') {
				delete(table, &str[1]);
			} else {
				int	sign_index	= 0;
				int ret 		= get_sign_index(str, &sign_index);
				if (ret == 1) {
					insert(table, str, sign_index);
				} else {
					char	*search_result = search(table, str);
					if (search_result) {
						printf("%s\n", search_result);
					} else {
						printf("%s: Not found\n", str);
					}
					// clock_t end = clock();
					// printf("Time passed in search = %f\n", (double)(end - w_start) / CLOCKS_PER_SEC);
				}
			}
		} else {
			// clock_t end2		= clock();
			// printf("Total time passed = %f\n", (double)(end2 - begin) / CLOCKS_PER_SEC);
			return (1);
		}
	}
	// clock_t end2		= clock();
	// printf("Total time passed = %f\n", (double)(end2 - begin) / CLOCKS_PER_SEC);
	return 0;
}