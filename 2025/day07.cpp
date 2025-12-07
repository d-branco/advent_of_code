/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day07.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/07 06:23:14      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/07 07:01:10     #########  #########  ###      ###      */
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
	file.close();

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
	size_t		count = 0;

	std::string line;
	getline(file, line);
	dprint("Line   Width: " << line.size());
	std::string mem = line;
	size_t		i	= 0;
	while (i < mem.size())
	{
		if (mem[i] == 'S')
		{
			dprint("Start found!");
			mem[i] = '|';
			dprint("");
			dprint("Output: " << line);
		}
		i++;
	}

	while (getline(file, line))
	{
		i = 0;
		while (i < line.size())
		{
			if ((mem[i] == '|') && (line[i] != '^'))
			{
				line[i] = '|';
			}
			else if ((mem[i] == '|') && (line[i] == '^'))
			{
				mem[i] = '.';
				count++;
				if (i > 0)
				{
					mem[i - 1] = '|';
				}
				if (i < line.size())
				{
					mem[i + 1] = '|';
				}
			}
			i++;
		}
		dprint("Output: " << line);
	}

	std::cout << "Part one: Split count: " << count << "\n";
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
	if (!file.good())
	{
		std::cout << "Error: Could nor access file " << INPUT_FILE << "\n";
		return (EXIT_FAILURE);
	}
	dprint(INPUT_FILE << " is good");

	return (EXIT_SUCCESS);
}
