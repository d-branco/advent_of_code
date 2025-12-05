/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day05.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/05 06:47:03      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/05 09:37:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
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

// Add a space in the empty line in the middle of the input
void part_one(std::ifstream &file)
{
	int			count = 0;
	std::string line;
	while (getline(file, line))
	{
		if (line == " ")
		{
			// dprint("Breakpoint");
			break;
		}
		// dprint("Skipping: " << line);
	}

	std::vector<long long> ids;
	while (getline(file, line))
	{
		ids.push_back(std::atol(line.c_str()));
		// dprint("Added to vector: " << ids[ids.size() - 1]);
	}
	// dprint("");

	file.clear();
	file.seekg(0, std::ios::beg);
	long long start;
	long long end;
	while (getline(file, line, '-') && (line[0] != ' '))
	{
		// dprint("Processing range: " << line);
		start = std::atol(line.c_str());
		getline(file, line);
		end				= std::atol(line.c_str());
		unsigned long i = 0;
		while (i < ids.size())
		{
			// dprint("Checking id: " << ids[i] << " (between " << start
			// << " and " << end << ")");
			if (ids[i] == 0)
			{
				i++;
				continue;
			}
			if ((ids[i] >= start && ids[i] <= end))
			{
				// dprint("Certified FRESH: " << ids[i]);
				ids[i] = 0;
				count++;
			}

			i++;
		}
	}
	// dprint("");

	std::cout << "Par one: Count: " << count << "\n";

	// Part two

	file.clear();
	file.seekg(0, std::ios::beg);
	long long sum_range = 0;
	long long range;
	(void) sum_range;
	(void) range;
	std::set<int> unique_ids;
	while (getline(file, line))
	{
		if (line == " ")
		{
			// dprint("Breakpoint");
			break;
		}
		// dprint("Skipping: " << line);
	}
	std::vector<long long> id2;
	while (getline(file, line))
	{
		id2.push_back(std::atol(line.c_str()));
		// dprint("Added to vector: " << id2[id2.size() - 1]);
	}

	file.clear();
	file.seekg(0, std::ios::beg);
	while (getline(file, line, '-') && (line[0] != ' '))
	{
		start = std::atol(line.c_str());
		getline(file, line);
		end = std::atol(line.c_str());
		dprint("Processing range: " << start << " to " << end);
		unsigned long i = 0;
		while (i < id2.size())
		{
			if ((id2[i] >= start && id2[i] <= end))
			{
				for (long long j = start; j <= end; j++)
				{
					dprint("Adding: " << j);
					unique_ids.insert(j);
				}
				dprint("Added rages from " << start << " and " << end);
				range = end - start + 1;
				dprint("Range: " << range);
				break;
			}

			i++;
		}
	}
	dprint("");

	std::cout << "Par two: Count: " << unique_ids.size() << "\n";
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
