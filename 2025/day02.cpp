/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day02.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/02 06:44:08      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/06 10:28:06     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

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
	std::string line;
	std::getline(file, line);
	// dprint("Input file content: " << line);
	unsigned long	   adding_all = 0;
	std::istringstream ss_line(line);
	std::string		   range_str;
	unsigned int	   first;
	unsigned int	   last;
	std::string		   id_str;
	while (getline(ss_line, range_str, ','))
	{
		// dprint("Range: " << range_str);
		std::istringstream ss_range(range_str);
		getline(ss_range, id_str, '-');
		first = std::atoi(id_str.c_str());
		// dprint("First element: " << first);
		getline(ss_range, id_str);
		last = std::atoi(id_str.c_str());
		dprint("First element: " << first << " Last element: " << last);

		bool invalid = false;
		for (unsigned int ite = first; ite <= last; ite++)
		{
			// dprint("Inside range: " << ite);

			std::stringstream ss_nbr;
			ss_nbr << ite;
			std::string nbr_str = ss_nbr.str();
			std::string comp;
			for (unsigned int k = (nbr_str.length() - 1); k >= 1; k--)
			{
				if (((nbr_str.length() % k) != 0)
					|| (((nbr_str.length() / k) % 2) != 0))
				{
					continue;
				}

				// dprint("TESTE: Sequence size: " << k << " repeats "
				// 								<< (nbr_str.length() / k)
				// 								<< " times");
				bool compare = true;
				for (unsigned int m = 0; m < nbr_str.length(); m += k)
				{
					if (m == 0)
					{
						comp = nbr_str.substr(0, k);
						// dprint("TESTE: Sequence for comparisson: "
						// 	   << nbr_str.substr(0, k));
					}
					if (comp == nbr_str.substr(m, k))
					{
						// dprint("Sequence: " << nbr_str.substr(m, k)
						// 					<< " is similar");
					}
					else
					{
						// dprint("Sequence: " << nbr_str.substr(m, k)
						// 					<< " does not compare to " << comp);
						compare = false;

						break;
					}
				}
				if ((compare))
				{
					adding_all += ite;
					dprint("Sequence found to be INVALID! (size: "
						   << k << ") iteration: [" << ite
						   << "] Sum: " << adding_all);
					invalid = true;

					break;
				}
			}
			// dprint("");
		}
		if (invalid)
		{
			// dprint("Range from: " << first << " to: " << last
			// 					  << " is INVALID Sum: " << adding_all);
		}
		else
		{
			// dprint("Range from: " << first << " to: " << last
			// 					  << " is valid Sum: " << adding_all);
		}
		dprint("");
	}

	std::cout << "Sum: " << adding_all << "\n";
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
