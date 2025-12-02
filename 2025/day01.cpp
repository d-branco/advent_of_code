/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day01.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/01 07:30:05      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/02 06:43:54     #########  #########  ###      ###      */
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
const int INITIAL_POS = 50;
const int DIAL_DIV	  = 100;

int		  input_validation(int argc, char **argv, std::ifstream &file);
void	  part_one(std::ifstream &file);
void	  part_two(std::ifstream &file);

int		  main(int argc, char **argv)
{
	dprint("Debug mode activated");
	std::ifstream file(INPUT_FILE);
	if (input_validation(argc, argv, file) != 0)
	{
		return (EXIT_FAILURE);
	}

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
	int			 pos   = INITIAL_POS;
	unsigned int count = 0;
	dprint("Initial position: " << pos);
	std::string input_line;
	while (std::getline(file, input_line) != 0)
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
			if (pos == 0)
			{
				--count;
			}
			pos -= std::atoi(input_line.c_str());
		}
		if (pos == 0)
		{
			++count;
		}
		while (pos >= DIAL_DIV)
		{
			pos -= DIAL_DIV;
			++count;
		}
		while (pos < 0)
		{
			pos += DIAL_DIV;
			++count;
			if (pos == 0)
			{
				++count;
			}
		}

		dprint("Current position: " << pos << " count: " << count);
	}

	std::cout << "Part two: Password: " << count << "\n";
}

void part_one(std::ifstream &file)
{
	int			 pos   = INITIAL_POS;
	unsigned int count = 0;
	dprint("Initial position: " << pos);
	std::string input_line;
	while (std::getline(file, input_line) != 0)
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
		while (pos >= DIAL_DIV)
		{
			pos -= DIAL_DIV;
		}
		while (pos < 0)
		{
			pos += DIAL_DIV;
		}
		if (pos == 0)
		{
			++count;
		}
		dprint("Current position: " << pos);
	}

	std::cout << "Part one: Password: " << count << "\n";
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