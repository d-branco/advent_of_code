/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day08.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/08 07:01:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/08 07:37:05     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifdef DEBUG
# define dprint(msg) std::cout << "==DEBUG== " << msg << "\n"
#else
# define dprint(msg) ((void) 0)
#endif

#define INPUT_FILE argv[1]

int	 input_validation(int argc, char **argv, std::ifstream &file);
void part_one(std::ifstream &file);
void part_two(std::ifstream &file);

typedef struct s_coo
{
	long long x;
	long long y;
	long long z;
} t_coo;

int main(int argc, char **argv)
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

	std::cout << "Part two\n";
}

void part_one(std::ifstream &file)
{
	std::vector<t_coo> jun;

	std::string		   line;
	t_coo			   alba;
	while (getline(file, line, ','))
	{
		alba.x = std::atoi(line.c_str());
		getline(file, line, ',');
		alba.y = std::atoi(line.c_str());
		getline(file, line);
		alba.z = std::atoi(line.c_str());
		jun.push_back(alba);
		// dprint("New coordenates: (" << jun[jun.size() - 1].x << ", "
		// 							<< jun[jun.size() - 1].y << ", "
		// 							<< jun[jun.size() - 1].z << ")");
	}

	


	std::cout << "Part one: Result: " << "\n";
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
