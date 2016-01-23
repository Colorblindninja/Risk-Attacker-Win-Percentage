#pragma once
#ifndef _RISK_H_
#define _RISK_H_

class Dice
{
public:
	Dice();
	Dice(int sides);
	int getValue() const;
	int getPosition() const;
	void setPosition(const int num);
	bool setSides(const int sides);

	void roll();
	bool  operator<=(const Dice &rhs) const;
	bool  operator<(const Dice &rhs) const;
	bool  operator>(const Dice &rhs) const;
	bool  operator>=(const Dice &rhs) const;
private:
	int face_value;
	int position;
	int mSides;
};


int run(const int attack, const int defend, const int num, const int sides);


#endif