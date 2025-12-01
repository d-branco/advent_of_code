/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day04.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:30:40 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/04 10:09:58 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day04.c input04.h && ./a.out

#include "input04.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	int	appearances;

	appearances = 0;
	// HORIZONTAL
	i = 0;
	j = 0;
	while (j < 140)
	{
		i = 0;
		while (i < 140)
		{
			if ((j + 3) >= 140)
				break ;
			else if (((matrix[i][j] == 'X') && matrix[i][j + 1] == 'M'
				&& matrix[i][j + 2] == 'A' && matrix[i][j + 3] == 'S')
				|| ((matrix[i][j] == 'S') && matrix[i][j + 1] == 'A'
				&& matrix[i][j + 2] == 'M' && matrix[i][j + 3] == 'X'))
			{
				appearances++;
				//printf("Located at matrix[%d][%d] %c%c%c%c\n", i, j,
				//	matrix[i][j], matrix[i][j + 1], matrix[i][j + 2],
				//	matrix[i][j + 3]);
			}
			i++;
		}
		j++;
	}
	// VERTICAL
	i = 0;
	j = 0;
	while (j < 140)
	{
		i = 0;
		while (i < 140)
		{
			if ((i + 3) >= 140)
				i = 140 ;
			else if (((matrix[i][j] == 'X') && matrix[i + 1][j] == 'M'
				&& matrix[i + 2][j] == 'A' && matrix[i + 3][j] == 'S')
				|| ((matrix[i][j] == 'S') && matrix[i + 1][j] == 'A'
				&& matrix[i + 2][j] == 'M' && matrix[i + 3][j] == 'X'))
			{
				appearances++;
				//printf("Located at matrix[%d][%d] %c%c%c%c\n", i, j,
				//	matrix[i][j], matrix[i + 1][j], matrix[i + 2][j],
				//	matrix[i + 3][j]);
			}
			i++;
		}
		j++;
	}
	// downward diagonal
	i = 0;
	j = 0;
	while (j < 140)
	{
		i = 0;
		while (i < 140)
		{
			if ((i + 3) >= 140)
				i = 140;
			else if ((j + 3) >= 140)
				break ;
			else if (((matrix[i][j] == 'X') && matrix[i + 1][j + 1] == 'M'
				&& matrix[i + 2][j + 2] == 'A' && matrix[i + 3][j + 3] == 'S')
				|| ((matrix[i][j] == 'S') && matrix[i + 1][j + 1] == 'A'
				&& matrix[i + 2][j + 2] == 'M' && matrix[i + 3][j + 3] == 'X'))
			{
				appearances++;
				//printf("Located at matrix[%d][%d]\n", i, j);
			}
			i++;
		}
		j++;
	}
	// forward diagonal
	i = 0;
	j = 0;
	while (j < 140)
	{
		i = 0;
		while (i < 140)
		{
			if ((i + 3) >= 140)
				i = 140;
			else if ((j + 3) >= 140)
				break ;
			else if (((matrix[i + 3][j] == 'X') && matrix[i + 2][j + 1] == 'M'
				&& matrix[i + 1][j + 2] == 'A' && matrix[i][j + 3] == 'S')
				|| ((matrix[i + 3][j] == 'S') && matrix[i + 2][j + 1] == 'A'
				&& matrix[i + 1][j + 2] == 'M' && matrix[i][j + 3] == 'X'))
			{
				appearances++;
				//printf("Located at matrix[%d][%d]\n", i, j);
			}
			i++;
		}
		j++;
	}
	printf("XMAS appearances: %d\n", appearances); //2569
	// SECOND PART
	appearances = 0;
	i = 0;
	j = 0;
	while (j < 140)
	{
		i = 0;
		while (i < 140)
		{
			if ((i + 2) >= 140)
				i = 140;
			else if ((j + 2) >= 140)
				break ;
			else if (((matrix[i][j] == 'M') && (matrix[i][j + 2] == 'M')
				&& (matrix[i + 1][j + 1] == 'A')
				&& (matrix[i + 2][j] == 'S') && (matrix[i + 2][j + 2] == 'S'))
				|| ((matrix[i][j] == 'M') && (matrix[i][j + 2] == 'S')
				&& (matrix[i + 1][j + 1] == 'A')
				&& (matrix[i + 2][j] == 'M') && (matrix[i + 2][j + 2] == 'S'))
				|| ((matrix[i][j] == 'S') && (matrix[i][j + 2] == 'S')
				&& (matrix[i + 1][j + 1] == 'A')
				&& (matrix[i + 2][j] == 'M') && (matrix[i + 2][j + 2] == 'M'))
				|| ((matrix[i][j] == 'S') && (matrix[i][j + 2] == 'M')
				&& (matrix[i + 1][j + 1] == 'A')
				&& (matrix[i + 2][j] == 'S') && (matrix[i + 2][j + 2] == 'M')))
			{
				appearances++;
				//printf("Located at matrix[%d][%d]\n", i, j);
			}
			i++;
		}
		j++;
	}
	printf("X-MAS appearances: %d\n", appearances); //1998
	return (0);
}
