/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day09.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:52:38 by abessa-m          #+#    #+#             */
/*   Updated: 2024/12/10 09:19:36 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usage 
//	cc -Wall -Werror -Wextra day09.c input09.h && valgrind -q ./a.out

#include "input09.h"
//int	example0[5] = {1, 2, 3, 4, 5};
//int	example[19] = {2, 3, 3, 3, 1, 3, 3, 1, 2, 1, 4, 1, 4, 1, 3, 1, 4, 0, 2};
//int	line[19999]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		represent(int *ptr, int end);
static int	len_of_int(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
char		*ft_malloc_cat_sufix_and_free_string(char *s1, char *s2);
char		*ft_malloc_cat(const char *s1, const char *s2);
static void	add_chr(const char *src, char *dest, int *index);
size_t		ft_strlen(const char *s);
int			len_of_file(char str[100000][5], int i);

int	main(void)
{
	represent(example0, 5);
	printf("\n");
	represent(example, 19);
	printf("\n");
	represent(line, 19999);
}

void	represent(int *ptr, int end)
{
	int		i;
	int		k;
	char	str[100000][5];
	int		temp;
	int		len;
	long	checksum;
	int		len_dot;
	int		max;

	i = 0;
	while (i < end)
	{
		printf("%d", ptr[i]);
		i++;
	}
	printf("\n");
	i = 0;
	k = 0;
	while (i < end)
	{
		if ((i % 2) == 0) // If it's even
		{
			temp = 0;
			while (temp < ptr[i])
			{
				str[k][0] = '\0';
				//printf("(%d)", i);
				strcpy(str[k], ft_itoa(i/2));
				k++;
				temp++;
			}
		}
		if ((i % 2) == 1) // If it's odd
		{
			temp = 0;
			while (temp < ptr[i])
			{
				str[k][0] = '\0';
				//printf("(%d)", i);
				strcpy(str[k], ".");
				k++;
				temp++;
			}
		}
		i++;
	}
	len = k;
	str[k][0] = '\0';
	// Print///////////////////////////////////////////////////////////////////
	//printf("|");
	//i = 0;
	//while (str[i][0])
	//{
	//	printf("%s|", str[i]);
	//	i++;
	//}
	//printf("\n");
	// Moves the number to the first available memory space
	i = 0;
	while (str[i][0] != '\0')
	{
		if (str[i][0] != '.')
			max = ft_atoi(str[i]);
		i++;
	}
	while (max > 0)
	{
		i = 1;
		while (i < len)
		{
			if ((str[i][0] == '.') && (str[i - 1][0] != '.'))
			{
				len_dot = len_of_file(str, i);
				k = len;
				while(k > i)
				{
					if (ft_atoi(str[k]) == max)
					{
						if ((ft_isdigit(str[k][0])) && (str[k][0] != str[k - 1][0])
							&& (len_of_file(str, k) <= len_dot))
						{	
							str[i][0] = '\0';
							strcpy(str[i], str[k]);
							str[k][0] = '\0';
							strcpy(str[k], ".");
							// Print///////////////////////////////////////////////////////////////////
							//printf("|");
							//temp = 0;
							//while (str[temp][0])
							//{
							//	printf("%s|", str[temp]);
							//	temp++;
							//}
							//printf("\n");
							///
							printf("(%d)", max);
							break ;
						}
					}
					k--;
				}
			}
			i++;
		}
		max--;
	}
	//printf("\n");
	// Print///////////////////////////////////////////////////////////////////
	//printf("|");
	//i = 0;
	//while (str[i][0])
	//{
	//	printf("%s|", str[i]);
	//	i++;
	//}
	//printf("\n");
	// Calculate the checksum
	checksum = 0;
	i = 0;
	while (i < len)
	{
		if (str[i][0] != '.')
		{
			checksum += i * ft_atoi(str[i]);
			printf("(%ld)", checksum);
		}
		i++;
	}
	printf("\n");
	printf("Checksum: %ld\n", checksum);
} // 825498124 too low
// 6211348208140

int	len_of_file(char str[100000][5], int i)
{
	int	len;
	int	j;

	len = 0;
	j = 0;
	while (str[i + len][j] == str[i + len + 1][j])
	{
		if (str[i + len][j] == '\0')
		{
			len++;
			j = -1;
		}
		j++;
	}
	return (len);
}

int	ft_atoi(const char *nptr)
{
	int			nbr;
	int			sign;
	size_t		j;

	j = 0;
	while (nptr[j] == 32
		|| (nptr[j] >= 9 && nptr[j] <= 13))
		j++;
	sign = 1;
	if (nptr[j] == '+' || nptr[j] == '-')
	{
		if (nptr[j] == '-')
			sign = -1;
		j++;
	}
	nbr = 0;
	while (ft_isdigit(nptr[j]))
	{
		nbr = (10 * nbr) + (nptr[j] - '0');
		j++;
	}
	nbr *= sign;
	return (nbr);
}

char	*ft_itoa(int n)
{
	long int		nbr;
	int				len;
	char			*str;
	int				j;

	len = len_of_int(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	j = 0;
	nbr = n;
	if (n < 0)
		nbr = -nbr;
	while (j < len)
	{
		str[len - j - 1] = '0' + nbr % 10;
		nbr /= 10;
		j++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	len_of_int(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

// WARNING: s1 has to be dynamicly allocated
// (this means, it needs to be allocated with malloc previously)
char	*ft_malloc_cat_sufix_and_free_string(char *s1, char *s2)
{
	char	*result;

	result = ft_malloc_cat(s1, s2);
	free(s1);
	return (result);
}

char	*ft_malloc_cat(const char *s1, const char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	add_chr(s1, result, &i);
	add_chr(s2, result, &i);
	result[i] = '\0';
	return (result);
}

static void	add_chr(const char *src, char *dest, int *index)
{
	int	j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[*index] = src[j];
		(*index)++;
		j++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}