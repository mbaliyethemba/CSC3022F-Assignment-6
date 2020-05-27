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

//filling the grid for working
void grid::fill(){
	grid g, a;
	state s;
	s.set_value(1.0);
	g.world = {{s,s,s},{s,s,s}};
	a.world = g.world;
	int itr = 0;
}



