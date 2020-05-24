//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 6
//29 May 2020

#include <vector>
#include <map>
#include <iostream>

#ifndef STATE_H
#define STATE_H

class state{
	private:
		std::vector<char> action;
		std::map<int, int> reward;
		int state_number;
		float discount, probability, val;
	
	public:
		state();
		~state();
		state(std::vector<char>, std::map<int,int>, int, int, float, float);
};

#endif
