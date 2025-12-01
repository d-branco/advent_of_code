/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 07:51:30 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/06 16:29:03 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day06.c input06.h && ./a.out

#include "input06.h"
//	example[10][10], struct s_guard
//
//	typedef struct s_guard
//	{
//		int	x;
//		int	y;
//		int	dir_x;
//		int	dir_y;
//	}	t_guard;
//
#include <stdio.h>
// printf()
#include <unistd.h>

void	print_example_grid(char grid[10][10]);
void	print_first_grid(char grid[130][130]);
int		check_if_it_loops(char grid[130][130], int obs_x, int obs_y);

int	main(void)
{
	t_guard	guard;
	int		steps;
	int		loop;
	int		x;
	int		y;
	int		count;
	char	grid[130][130];

	// EXAMPLE
	steps = 1;
	print_example_grid(example);
	// pos_x    pos_y    dir_x    dir_y
	guard.x = 4;
	guard.y = 6;
	guard.dir_x = 0;
	guard.dir_y = -1;
	while ((guard.x > 0 && guard.x < 10) && (guard.y > 0 && guard.y < 10))
	{
		while ((example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
			|| (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '<')
			|| (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '>')
			|| (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == 'v')
			|| (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '^')
			)
		{
			if (example[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
				steps++;
			if (guard.dir_x == 1)
				example[guard.y][guard.x] = '>';
			if (guard.dir_x == -1)
				example[guard.y][guard.x] = '<';
			if (guard.dir_y == 1)
				example[guard.y][guard.x] = 'v';
			if (guard.dir_y == -1)
				example[guard.y][guard.x] = '^';
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
		}
		// going outside
		if ((guard.x + guard.dir_x) < 0 || (guard.x + guard.dir_x) >= 10
			|| (guard.y + guard.dir_y) < 0 || (guard.y + guard.dir_y) >= 10)
		{
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			break ;
		}
		example[guard.y][guard.x] = '@';
		//printf("\n");
		//print_example_grid(example);
		//rotate tau / 4
		if (guard.dir_x == 1)
		{
			guard.dir_x = 0;
			guard.dir_y = 1;
		}
		else if (guard.dir_y == 1)
		{
			guard.dir_x = -1;
			guard.dir_y = 0;
		}
		else if (guard.dir_x == -1)
		{
			guard.dir_x = 0;
			guard.dir_y = -1;
		}
		else if (guard.dir_y == -1)
		{
			guard.dir_x = 1;
			guard.dir_y = 0;
		}
	//printf("Steps: %d\n", steps);
	}
	printf("\n");
	print_example_grid(example);
	printf("Steps: %d\n\n", steps);
	//	PART ONE
	y = 0;
	while (y < 130)
	{
		x = 0;
		while (x < 130)
		{
			grid[y][x] = first[y][x];
			x++;
		}
		y++;
	}
	steps = 1;
	print_first_grid(first);
	// pos_x    pos_y    dir_x    dir_y
	guard.x = 70;
	guard.y = 59;
	guard.dir_x = 0;
	guard.dir_y = -1;
	while ((guard.x > 0 && guard.x < 130) && (guard.y > 0 && guard.y < 130))
	{
		while ((grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
			|| (grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == '<')
			|| (grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == '>')
			|| (grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == 'v')
			|| (grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == '^')
			)
		{
			if (grid[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
				steps++;
			if (guard.dir_x == 1)
				grid[guard.y][guard.x] = '>';
			if (guard.dir_x == -1)
				grid[guard.y][guard.x] = '<';
			if (guard.dir_y == 1)
				grid[guard.y][guard.x] = 'v';
			if (guard.dir_y == -1)
				grid[guard.y][guard.x] = '^';
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
		}
		// going outside
		if ((guard.x + guard.dir_x) < 0 || (guard.x + guard.dir_x) >= 130
			|| (guard.y + guard.dir_y) < 0 || (guard.y + guard.dir_y) >= 130)
		{
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			break ;
		}
		grid[guard.y][guard.x] = '@';
		//printf("\n");
		//print_first_grid(grid);
		//rotate tau / 4
		if (guard.dir_x == 1)
		{
			guard.dir_x = 0;
			guard.dir_y = 1;
		}
		else if (guard.dir_y == 1)
		{
			guard.dir_x = -1;
			guard.dir_y = 0;
		}
		else if (guard.dir_x == -1)
		{
			guard.dir_x = 0;
			guard.dir_y = -1;
		}
		else if (guard.dir_y == -1)
		{
			guard.dir_x = 1;
			guard.dir_y = 0;
		}
	//printf("Steps: %d\n", steps);
	}
	printf("\n");
	print_first_grid(grid);
	printf("Steps: %d\n\n", steps);
	// 5095
	//	PART TWO
	count = 0;
	y = 0;
	while (y < 130)
	{
		x = 0;
		while (x < 130)
		{
			if (first[y][x] == '.')
			{
				loop = check_if_it_loops(first, x, y);
				if (loop == 0)
					printf(".");
				else
				{
					printf("L");
					count++;
				}
			}
			else
				printf(".");
			x++;
		}
		printf("|\n");
		y++;
	}
	// 247 TOO LOW
	// 621 TOO LOW
	printf("Count: %d\n", count);
	//2128 TOO HIGH
	//1937 wrong
	//1939 wrong but coincides with someone else
	// 1933
	return (0);
}

int	check_if_it_loops(char grid[130][130], int obs_x, int obs_y)
{
	int		loop;
	int		steps;
	t_guard	guard;
	int		x;
	int		y;
	char	first[130][130];
	int		iter;

	iter = 0;
	steps = 1;
	y = 0;
	while (y < 130)
	{
		x = 0;
		while (x < 130)
		{
			first[y][x] = grid[y][x];
			x++;
		}
		y++;
	}
	first[obs_y][obs_x] = '#';
	loop = 0;
	//printf("\n");
	//print_first_grid(first);
	// pos_x    pos_y    dir_x    dir_y
	guard.x = 70;
	guard.y = 59;
	guard.dir_x = 0;
	guard.dir_y = -1;
	if (obs_x == guard.x && obs_y == guard.y)
		return (0);
	while ((guard.x > 0 && guard.x < 130) && (guard.y > 0 && guard.y < 130))
	{
		while ((first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
			|| (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '<')
			|| (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '>')
			|| (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == 'v')
			|| (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '^')
			)
		{
			if (first[guard.y + guard.dir_y][guard.x + guard.dir_x] == '.')
				steps++;
			else if (guard.dir_x == 1)
			{
				if (first[guard.y][guard.x] == '.')
					first[guard.y][guard.x] = '>';
			}
			else if (guard.dir_x == -1)
			{
				if (first[guard.y][guard.x] == '.')
					first[guard.y][guard.x] = '<';
			}
			else if (guard.dir_y == 1)
			{
				if (first[guard.y][guard.x] == '.')
					first[guard.y][guard.x] = 'v';
			}
			else if (guard.dir_y == -1)
			{
				if (first[guard.y][guard.x] == '.')
					first[guard.y][guard.x] = '^';
			}
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			//printf("\n");
			//printf("Obstacle in [%.3d][%.3d]. \n", obs_x, obs_y);
			//print_first_grid(first);
			if (loop == 1)
				break ;
		}
		iter++;
		if (iter > 2000) /////////////////////////////////////// ITERATOR LIMIT
		{
			//printf("\n");
			//print_first_grid(first);
			loop = 1;
		}
		if (loop == 1)
			break ;
		// going outside
		if ((guard.x + guard.dir_x) < 0 || (guard.x + guard.dir_x) >= 130
			|| (guard.y + guard.dir_y) < 0 || (guard.y + guard.dir_y) >= 130)
		{
			guard.x += guard.dir_x;
			guard.y += guard.dir_y;
			break ;
		}
		//first[guard.y][guard.x] = '@';
		//printf("\n");
		//print_first_grid(first);
		//rotate tau / 4
		if (guard.dir_x == 1)
		{
			guard.dir_x = 0;
			guard.dir_y = 1;
		}
		else if (guard.dir_y == 1)
		{
			guard.dir_x = -1;
			guard.dir_y = 0;
		}
		else if (guard.dir_x == -1)
		{
			guard.dir_x = 0;
			guard.dir_y = -1;
		}
		else if (guard.dir_y == -1)
		{
			guard.dir_x = 1;
			guard.dir_y = 0;
		}
	}
	//if (loop == 1)
	//{
	//	printf("\n");
	//	print_first_grid(first);
	//}
	return (loop);
}

void	print_first_grid(char grid[130][130])
{
	int	y;
	int	x;

	y = 0;
	while (y < 130)
	{
		x = 0;
		while (x < 130)
		{
			printf("%c", grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_example_grid(char grid[10][10])
{
	int	y;
	int	x;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			printf("%c", grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
