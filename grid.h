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
	
	public:
		grid();
		~grid();
		grid(std::vector<std::vector<state>> v);
		bool converge(grid g);
		void fill();
		void printGrid(int num);
		std::vector<state> optimal_policy(state s);
		state optimal_state(std::vector<state> v);
};
#endif
