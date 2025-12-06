/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   day06.cpp                            :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/12/06 10:28:06      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/12/06 12:04:49     #########  #########  ###      ###      */
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
	std::string lin1;
	std::string lin2;
	std::string lin3;
	std::string lin4;
	std::string oper;

	std::getline(file, lin1);
	std::getline(file, lin2);
	std::getline(file, lin3);
	std::getline(file, lin4);
	std::getline(file, oper);

	size_t			   pos = 0;
	size_t			   i;
	unsigned long long eins;
	unsigned long long zwei;
	unsigned long long drei;
	unsigned long long vier;
	char			   op;
	(void) op;
	unsigned long long temp;
	unsigned long long sum = 0;
	while (pos < oper.length())
	{
		for (i = 0; oper[pos + i] != '\0'; i++)
		{
			if ((lin1[pos + i] == ' ') && (lin2[pos + i] == ' ')
				&& (lin3[pos + i] == ' ') && (lin4[pos + i] == ' ')
				&& (oper[pos + i] == ' '))
			{
				break;
			}
		}

		eins = std::atoi(lin1.substr(pos, i).c_str());
		zwei = std::atoi(lin2.substr(pos, i).c_str());
		drei = std::atoi(lin3.substr(pos, i).c_str());
		vier = std::atoi(lin4.substr(pos, i).c_str());
		if (oper[pos] == '+')
		{
			op	 = '+';
			temp = eins + zwei + drei + vier;
		}
		else if (oper[pos] == '*')
		{
			op	 = '*';
			temp = eins * zwei * drei * vier;
		}
		else
		{
			std::cerr << "Error: could not find operator!\n";
			return;
		}
		sum += temp;
		dprint("substr size: " << i << " -> \'" << eins << "\' " << op << " \'"
							   << zwei << "\' " << op << " \'" << drei << "\' "
							   << op << " \'" << vier << "\' = " << temp
							   << "  sum: " << sum);
		pos = pos + i + 1;
	}

	std::cout << "Part one: Grand total: " << sum << "\n";
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
