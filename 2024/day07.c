/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day07.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:17:25 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/07 20:12:15 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day07.c input07.h && ./a.out

#include "input07.h"
//	int example[9][6] =
//	{
//	{190, 10, 19, 0, 0, 0}, {3267, 81, 40, 27, 0, 0}, {83, 17, 5, 0, 0, 0},
//	{156, 15, 6, 0, 0, 0},  {7290, 6, 8, 6, 15, 0},  {161011, 16, 10, 13, 0, 0},
//	{192, 17, 8, 14, 0, 0}, {21037, 9, 7, 18, 13, 0}, {292, 11, 6, 16, 20, 0}
//	};
//	input[850][];
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		i;
	int		j;
	int		n_spaces;
	int		n_operators;


	n_operators = 2; // +, *
	i = 0;
	while (i < 9)
	{
		// Line begins
		printf("%.3d:% 7.d: %.2d", i, example[i][0], example[i][1]);
		j = 2;
		while (example[i][j] != 0)
		{
			printf(" %.2d", example[i][j]);
			j++;
		}
		printf("\n");
		// Calculate the number of spaces
		j = 2;
		while (example[i][j] != 0)
			j++;
		n_spaces = j - 2;
		// For each possibility, determine the operators
		j = 0;
		while (j < n_spaces)
		{
			
			j++;
		}




		printf("\n");
		i++;
	}
	return (0);
}

void	recursion(int current_value, int j)
{
	if 
}
