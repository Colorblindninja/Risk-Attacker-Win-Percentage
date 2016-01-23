#include "risk.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		std::cout << "usage: " << argv[0] << "num of attacking die, num of defending die, num of simnulations, num sides on die" << std::endl;
		return 1;
	}

	std::srand(std::time(0));
	int att_die = std::atoi(argv[1]);
	int def_die = std::atoi(argv[2]);
	int sims = std::atoi(argv[3]);
	int sides = std::atoi(argv[4]);
	int attWins = run(att_die, def_die, sims, sides);

	int smallest = 0;
	if (att_die < def_die)
	{
		smallest = att_die;
	}
	else
	{
		smallest = def_die;
	}
	float percent = float(attWins) / (sims * smallest);

	std::cout << argv[1] << " vs " << argv[2] << " = " << percent *100 << "%"  << std::endl; 

	
	int lol;
	std::cin >> lol;
	return 0;
}