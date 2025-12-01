/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day01.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/01 07:30:05      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/01 08:17:57     #########  #########  ###      ###      */
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

#define INPUT_FILE	argv[1]
#define INITIAL_POS 50

bool input_validation(int argc, char **argv, std::ifstream &file);
void part_one(std::ifstream &file);
void part_two(std::ifstream &file);

int	 main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream file(INPUT_FILE);
	if (input_validation(argc, argv, file))
	{
		return (EXIT_FAILURE);
	}

	part_one(file);

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
	int			 pos   = INITIAL_POS;
	unsigned int count = 0;
	dprint("Initial position: " << pos);
	std::string input_line;
	while (std::getline(file, input_line))
	{
		// dprint("Read line: " << input_line);
		if (input_line[0] == 'R')
		{
			// dprint("Rotating right");
			input_line = input_line.substr(1);
			dprint("Rotating right " << input_line << " times");
			pos += std::atoi(input_line.c_str());
		}
		else
		{
			// dprint("Rotating left");
			input_line = input_line.substr(1);
			dprint("Rotating left " << input_line << " times");
			pos -= std::atoi(input_line.c_str());
		}
		while (pos >= 100)
		{
			pos -= 100;
		}
		while (pos < 0)
		{
			pos += 100;
		}
		if (pos == 0)
		{
			++count;
		}
		dprint("Current position: " << pos);
	}

	std::cout << "Part one: Password: " << count << "\n";
}

bool input_validation(int argc, char **argv, std::ifstream &file)
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
	dprint("");

	return (EXIT_SUCCESS);
}