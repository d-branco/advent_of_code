/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:48:44 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/02 20:18:29 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day01.c input01.h && ./a.out

#include <stdlib.h>
// qsort(), abs()
#include <stdio.h>
// printf()
#include "input01.h"
// list_left[], list_right[]

int	order_function(const void *a, const void *b);

int	main(void)
{
	int	result;
	int	i;
	int	j;
	int	n_repetitions;

	qsort(list_left, 1000, sizeof(int), order_function);
	qsort(list_right, 1000, sizeof(int), order_function);
	result = 0;
	i = 0;
	while (i < 1000)
	{
		result += abs(list_left[i] - list_right[i]);
		//printf("abs(%d - %d) = %d \n",
		//	list_left[i], list_right[i], abs(list_left[i] - list_right[i]));
		i++;
	}
	printf("Total distance: %d\n", result);
	result = 0;
	i = 0;
	while (i < 1000)
	{
		n_repetitions = 0;
		j = 0;
		while (j < 1000)
		{
			if (list_left[i] == list_right[j])
			{
				//printf("left[%d] %d = %d right[%d]\n", i,
				//	list_left[i], list_right[j], j);
				n_repetitions++;
				//printf("repetition: %d\n", n_repetitions);
			}
			j++;
		}
		result = result + (list_left[i] * n_repetitions);
		i++;
	}
	printf("Similarity score: %d\n", result);
	return (0);
}

int	order_function(const void *a, const void *b)
{
	int	difference;

	difference = *(int *)a - *(int *)b;
	return (difference);
}
