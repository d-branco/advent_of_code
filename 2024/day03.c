/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:49:26 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/04 10:06:31 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day03.c input03.h && ./a.out

#include "input03.h"
//	unsigned long	input_addition(void)
#include <stdio.h>

unsigned long	ft_mul(int a, int b);

int	main(void)
{
	unsigned long	result;

	result = input_addition();
	printf("Result: %ld\n", result);
	result = do_and_dont_addition();
	printf("Result: %ld\n", result);
	return (0);
}

unsigned long	ft_mul(int a, int b)
{
	unsigned long	result;

	result = a * b;
	return (result);
}
