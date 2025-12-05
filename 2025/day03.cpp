/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day03.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/03 06:54:07      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/05 08:41:46     #########  #########  ###      ###      */
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
	unsigned long count = 0;
	std::string	  input_line;
	while (std::getline(file, input_line) != 0)
	{
		dprint("Line: " << input_line);
		char nbr1 = 0;
		char nbr2 = 0;
		for (unsigned int i = 0; i < input_line.size(); i++)
		{
			if ((input_line[i] > nbr1) && (i != (input_line.size() - 1)))
			{
				nbr1 = input_line[i];
				nbr2 = 0;
				continue;
			}
			if (input_line[i] > nbr2)
			{
				nbr2 = input_line[i];
			}
		}
		dprint("nbr1 " << nbr1);
		dprint("nbr2 " << nbr2);
		unsigned int nbr = (((nbr1 - '0') * 10) + (nbr2 - '0'));
		dprint("sum: " << nbr);
		count += nbr;
	}

	std::cout << "Part one: Sum: " << count << "\n";
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