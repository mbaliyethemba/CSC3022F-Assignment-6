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
		state(std::vector<char> a, std::map<int,int> r, int s, int v, float d, float p);
		void set_value(float v);
		void set_discount(float d);
		void set_probability(float p);
		void set_state_number(int s);	
};

#endif
