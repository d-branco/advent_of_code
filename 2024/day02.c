/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:20:47 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/06 18:02:08 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day02.c input02.h && ./a.out

#include "input02.h"
// int report[1000][9]
#include <stdio.h>
// printf()

int	is_safe(int vector[9]);

int	main(void)
{
	int	i;
	int	safe;
	int	safe_number;
	int	k;
	int	temp[9];
	int	l;

	i = 0;
	safe_number = 0;
	while (i < 1000)
	{
		printf("\n%.4d: %.2d %.2d %.2d %.2d %.2d %.2d %.2d %.2d %.2d ", i + 1,
			report[i][0], report[i][1], report[i][2], report[i][3],
			report[i][4], report[i][5], report[i][6], report[i][7],
			report[i][8]);
		safe = is_safe(report[i]);
		if (safe == 1)
		{
			safe_number++;
			printf(" SAFE!");
		}
		else
		{
			k = 0;
			while (k < 9)
			{
				l = 0;
				while (l < 9)
				{
					temp[l] = report[i][l];
					l++;
				}
				temp[k] = 0;
				l = 0;
				while (l < 8)
				{
					if (temp[l] == 0)
					{
						temp[l] = temp[l + 1];
						temp[l + 1] = 0;
					}
					l++;
				}
				//One number removed
				printf("\n%.4d: %.2d %.2d %.2d %.2d %.2d %.2d %.2d %.2d %.2d ",
					i + 1, temp[0], temp[1], temp[2], temp[3],
					temp[4], temp[5], temp[6], temp[7], temp[8]);
				if (is_safe(temp) == 1)
				{
					safe_number++;
					printf(" SAFE!");
					break ;
				}
				k++;
			}
			//safe = 0;
			//test it
			//if safe
			//		safe_number++
			//		break ;
		}
		i++;
	}
	printf("\nNumber of safe reports: %d\n", safe_number);
	// 483 wrong
	// 531 right
}

int	is_safe(int vector[9])
{
	int	safe;
	int	level;
	int	j;

	level = 0;
	safe = 1;
	j = 0;
	while (vector[j + 1] != 0)
	{
		if (vector[j + 1] == vector[j]) // if not increasinf
		{
			safe--;
			//printf("    not increasing");
			j++;
			continue ;
		}
		else if (vector[j + 1] > vector[j]) // if increasing
		{
			if (((vector[j + 1] - vector[j]) > 3) // too fast
				|| (level == -1)) // decreased before
			{
				//if ((vector[j + 1] - vector[j]) > 3)
				//	printf("    increase too fast from %d to %d",
				//		vector[j], vector[j + 1]);
				//if (level == -1)
				//	printf("    increasing after having decrease!");
				safe--;
				j++;
				continue ;
			}
			level = 1; // set level to increasing
		}
		else if (vector[j + 1] < vector[j]) // if decreasing
		{
			if (((vector[j] - vector[j + 1]) > 3) // too fast
				|| (level == 1)) // increased before
			{
				//if ((vector[j] - vector[j + 1]) > 3)
				//	printf("    decrease too fast from %d to %d",
				//		vector[j], vector[j + 1]);
				//if (level == 1)
				//	printf("    decreasing after having increased!");
				safe--;
				j++;
				continue ;
			}
			level = -1; // set level to decfreasing
		}
		j++;
	}
	return (safe);
}
