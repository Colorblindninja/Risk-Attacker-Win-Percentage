#include "risk.h"
#include <cstdlib>
#include <iostream>

Dice::Dice()
{
	face_value = 1;
	position = 0;
	mSides = 0;
}

Dice::Dice(int sides)
{
	face_value = 1;
	position = 0;
	mSides = sides;
}

int Dice::getValue() const
{
	return face_value;
}

int Dice::getPosition() const
{
	return position;
}

bool Dice::setSides(const int sides)
{
	mSides = sides;
	return true;
}

void Dice::setPosition(const int num)
{
	position = num;
}

void Dice::roll()
{
	face_value = rand() % mSides + 1;
}

bool  Dice::operator<=(const Dice &rhs) const
{
	if (face_value <= rhs.face_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool  Dice::operator<(const Dice &rhs) const
{
	if (face_value < rhs.face_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool  Dice::operator>(const Dice &rhs) const
{
	if (face_value > rhs.face_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool  Dice::operator>=(const Dice &rhs) const
{
	if (face_value >= rhs.face_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int run(const int attack, const int defend, const int num, const int sides)
{
	int i;
	Dice attackers[3];
	Dice defenders[2];
	for (i = 0; i < attack; i++)
	{
		attackers[i] = Dice(sides);
	}                                   // make the die

	for (i = 0; i < defend; i++)
	{
		defenders[i] = Dice(sides);
	}



	int j, attack_wins = 0;
	for (i = 0; i <= num; i++)
	{
		for (j = 0; j < attack; j++)
		{
			attackers[j].roll();          // roll the die
		}
		for (j = 0; j < defend; j++)
		{
			defenders[j].roll();
		}



		int att_Least = 0;
		int att_Big = 1;
		int att_med = 2;
		for (j = 0; j < attack; j++)
		{
			if (attackers[j] < attackers[att_Least])
			{
				att_Least = j;                           // find the biggest and smallest to compare against the others biggest, etc
			}
			if (attackers[j] > attackers[att_Big])
			{
				att_Big = j;
			}
		}
		if (attack == 3)
		{
			for (j = 0; j < attack; j++)
			{
				if (j != att_Big && j != att_Least)
				{
					int att_med = j;                             // only find the medium if they use three die
				}
			}
		}
		int def_Least = 1, def_Big = 0;
		for (j = 0; j < defend; j++)
		{
			if (defenders[j] < defenders[att_Least])
			{
				def_Least = j;
			}
			if (defenders[j] > defenders[att_Big])
			{
				def_Big = j;
			}
		}



		if (attackers[att_Big] > defenders[def_Big])
		{
			attack_wins++;
		}
		if (attack == 3 && defend != 1)
		{
			if (attackers[att_med] > defenders[def_Least])                      // compare them
			{
				attack_wins++;
			}
		}
		if (attack ==2  && defend != 1)
		{
			if (attackers[att_Least] > defenders[def_Least])
			{
				attack_wins++;
			}
		}
	}
	return attack_wins;
}