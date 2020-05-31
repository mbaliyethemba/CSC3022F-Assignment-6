//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 6
//29 May 2020

#include <vector>
#include <map>
#include "state.h"
#include <string>

#ifndef GRID_H
#define GRID_H

class grid{
	private:
		std::vector<std::vector<state>> world;
		std::vector<state> optimal_states;
		std::vector<state> optimal_states_2;
		int itrnum;
	
	public:
		grid();
		~grid();
		grid(std::vector<std::vector<state>> v);
		bool converge(grid g);
		void fill();
		void printAnswers();
		void optimal_policy();
		state optimal_state(std::vector<state> v);
		void to_string(int num);
		void write_optimal(std::vector<state> v);	
};
#endif
