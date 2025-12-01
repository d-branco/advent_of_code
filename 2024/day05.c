/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day05.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:16 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/05 21:04:25 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day05.c input05.h && ./a.out

#include "input05.h"
// example[6][5], example_rules[21][2], 
// first[194][23], first_rules[1176][2], 
#include <stdio.h>
// printf(), 

void	print_line(int i);

int	main(void)
{
	int	i;
	int	j;
	int	r;
	int	temp;
	int	correct;
	int	middle;

	middle = 0;
	i = 0;
	while (i < 6)
	{
		correct = 1;
		print_line(i);
		j = 1;
		while (j < 5)
		{
			r = 0;
			while (r < 21)
			{
				if ((example[i][j - 1] == example_rules[r][1])
					&& (example[i][j] == example_rules[r][0]))
				{
					temp = example[i][j - 1];
					example[i][j - 1] = example[i][j];
					example[i][j] = temp;
					printf("    ERROR with rule %.2d: %.2d|%.2d\n", r + 1,
						example_rules[r][0], example_rules[r][1]);
					print_line(i);
					j = 0;
					correct = 0;
					break ;
				}
				r++;
			}
			j++;
		}
		if (correct == 1)
		{
			printf("    CORRECT: ");
			temp = 1;
			while (example[i][5 - temp] == 0)
				temp++;
			middle += example[i][(5 - temp) / 2];
			printf("%.2d", example[i][(5 - temp) / 2]);
		}
		printf("\n");
		i++;
	}
	printf("Result of the example: %d\n\n", middle);
	// FIRST PART
	middle = 0;
	i = 0;
	while (i < 194)
	{
		correct = 1;
		print_line(i);
		j = 1;
		while (j < 23)
		{
			r = 0;
			while (r < 1176)
			{
				if ((first[i][j - 1] == first_rules[r][1])
					&& (first[i][j] == first_rules[r][0]))
				{
					temp = first[i][j - 1];
					first[i][j - 1] = first[i][j];
					first[i][j] = temp;
					printf("    ERROR with rule %.2d: %.2d|%.2d\n", r + 1,
						first_rules[r][0], first_rules[r][1]);
					print_line(i);
					j = 0;
					correct = 0;
					break ;
				}
				r++;
			}
			j++;
		}
		if (correct == 1)
		{
			printf("    CORRECT: ");
			temp = 1;
			while (first[i][23 - temp] == 0)
				temp++;
			middle += first[i][(23 - temp) / 2];
			printf("%.2d", first[i][(23 - temp) / 2]);
		}
		printf("\n");
		i++;
	}
	printf("Result of the first part: %d\n", middle); //4905
	// SECOND PART - comment first part to use this
	/*
	middle = 0;
	i = 0;
	while (i < 194)
	{
		correct = 1;
		print_line(i);
		j = 1;
		while (j < 23)
		{
			r = 0;
			while (r < 1176)
			{
				if ((first[i][j - 1] == first_rules[r][1])
					&& (first[i][j] == first_rules[r][0]))
				{
					temp = first[i][j - 1];
					first[i][j - 1] = first[i][j];
					first[i][j] = temp;
					printf("    ERROR with rule %.2d: %.2d|%.2d\n", r + 1,
						first_rules[r][0], first_rules[r][1]);
					print_line(i);
					j = 0;
					correct = 0;
					break ;
				}
				r++;
			}
			j++;
		}
		if (correct == 0)
		{
			printf("    CORRECT: ");
			temp = 1;
			while (first[i][23 - temp] == 0)
				temp += 2;
			middle += first[i][(23 - temp) / 2];
			printf("%.2d", first[i][(23 - temp) / 2]);
		}
		printf("\n");
		i++;
	}
	printf("Result of the second part: %d\n", middle); //6204
	*/
}

void	print_line(int i)
{
	printf("%.2d: %.2d %.2d %.2d %.2d %.2d", i + 1, example[i][0],
		example[i][1], example[i][2], example[i][3], example[i][4]);
}
