//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 6
//29 May 2020

#include "grid.h"
#include <algorithm>    // std::max
#include <fstream>
#include "float.h"

//default constructor
grid::grid(){
}

//default destructor
grid::~grid(){
}

//constructor
grid::grid(std::vector<std::vector<state>> v){
	this->world = v;
}

//converging the grid
bool grid::converge(grid g){
	for(size_t col = 0; col < this->world.size(); col++){
		for(size_t row = 0; row < this->world[col].size(); row++){
			if(this->world[col][row].get_value() != g.world[col][row].get_value()){
				return false;
			}
		}
	}
	return true;
}

//filling the grid for working
void grid::fill(){
	grid g, a;
	state s;
	s.set_value(1.0);
	g.world = {{s,s,s},{s,s,s}};
	a.world = g.world;
	int itr = 0;
}



