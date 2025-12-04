/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day04.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/04 05:50:07      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/04 06:38:19     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

#define INPUT_FILE argv[1]

int	 input_validation(int argc, char **argv, std::ifstream &file);
void part_one(std::ifstream &file);
void part_two(std::ifstream &file);

int	 main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream file(INPUT_FILE);
	if (input_validation(argc, argv, file) != 0)
	{
		return (EXIT_FAILURE);
	}
	dprint("");

	part_one(file);
	file.clear();
	file.seekg(0, std::ios::beg);
	part_two(file);

	dprint("");
	dprint("End of main()");
	return (EXIT_SUCCESS);
}

void part_two(std::ifstream &file)
{
	(void) file;
}

void part_one(std::ifstream &file)
{
	(void) file;
	int			count = 0;
	// first line
	std::string first;
	std::string second;
	std::getline(file, first);
	std::getline(file, second);

	dprint("First:  " << first);
	dprint("Second: " << second);
	size_t i	= 0;
	int	   surr = 0;
	if (first[i] == '@')
	{
		count++;
		dprint("Found at position: " << i);
	}
	while (i < first.size() - 1)
	{
		i++;
		if (first[i] != '@')
		{
			continue;
		}
		surr = 0;
		if (first[i - 1] == '@')
		{
			surr++;
		}
		if (first[i + 1] == '@')
		{
			surr++;
		}
		if (second[i] == '@')
		{
			surr++;
		}
		if (second[i - 1] == '@')
		{
			surr++;
		}
		if (second[i + 1] == '@')
		{
			surr++;
		}
		if (surr < 4)
		{
			count++;
			dprint("Found at position: " << i);
		}
	}

	file.clear();
	file.seekg(0, std::ios::beg);
	dprint("Count: " << count);
	dprint("");

	// midle line
	std::getline(file, first);
	std::getline(file, second);
	std::string third;
	while (getline(file, third) != 0)
	{
		if (third.size() < 1)
		{
			break;
		}
		dprint("First:  " << first);
		dprint("Second: " << second);
		dprint("Third:  " << third);
		i = 0;
		while (i < second.size())
		{
			if (second[i] != '@')
			{
				i++;
				continue;
			}
			surr = 0;
			if ((i > 0) && (second[i - 1] == '@'))
			{
				surr++;
			}
			if (second[i + 1] == '@')
			{
				surr++;
			}

			if (first[i] == '@')
			{
				surr++;
			}
			if ((i > 0) && (first[i - 1] == '@'))
			{
				surr++;
			}
			if (first[i + 1] == '@')
			{
				surr++;
			}

			if (third[i] == '@')
			{
				surr++;
			}
			if ((i > 0) && (third[i - 1] == '@'))
			{
				surr++;
			}
			if (third[i + 1] == '@')
			{
				surr++;
			}
			if (surr < 4)
			{
				count++;
				dprint("Found at position: " << i);
			}
			i++;
		}
		dprint("Count: " << count);
		first  = second;
		second = third;
		dprint("");
	}

	// end line
	i	 = 0;
	surr = 0;
	if (second[i] == '@')
	{
		count++;
		dprint("Found at position: " << i);
	}
	while (i < second.size() - 1)
	{
		i++;
		if (second[i] != '@')
		{
			continue;
		}
		surr = 0;
		if (second[i - 1] == '@')
		{
			surr++;
		}
		if (second[i + 1] == '@')
		{
			surr++;
		}
		if (first[i] == '@')
		{
			surr++;
		}
		if (first[i - 1] == '@')
		{
			surr++;
		}
		if (first[i + 1] == '@')
		{
			surr++;
		}
		if (surr < 4)
		{
			count++;
			dprint("Found at position: " << i);
		}
	}

	file.clear();
	file.seekg(0, std::ios::beg);
	dprint("Count: " << count);
	dprint("");

	std::cout << "Part one: Number of rolls: " << count << "\n";
}

int input_validation(int argc, char **argv, std::ifstream &file)
{
	dprint("");
	if (argc == 1)
	{
		std::cout << "Error: Missing input \nUsage: \n  ./dayXX input\n";
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		std::cout << "Error: Too many arguments \nUsage: \n  ./dayXX input\n";
		return (EXIT_FAILURE);
	}
	dprint("Input file: " << INPUT_FILE);

	dprint("Checking if file exists and is readable");
	// std::ifstream file = file(INPUT_FILE);
	if (!file.good())
	{
		std::cout << "Error: Could nor access file " << INPUT_FILE << "\n";
		return (EXIT_FAILURE);
	}
	dprint(INPUT_FILE << " is good");

	return (EXIT_SUCCESS);
}