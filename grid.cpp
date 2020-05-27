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
	while(this->converge(g) == 0){
		for(size_t c = 0; c < this->world.size(); c++){
			for(size_t r = 0; r <this->world[c].size(); r++){
				state next;
				for(char b: this->world[c][r].get_action()){
					switch(b){
						case 'u':{
							next = this->world[c-1][r];
							this->world[c][r].set_value(std::max(this->world[c][r].get_value(), this->world[c][r].get_reward()[next.get_state_number()] + this->world[c][r].get_discount()*next.get_value()));
						}
						break;
						
						case 'd':{
							next = this->world[c+1][r];
							this->world[c][r].set_value(std::max(this->world[c][r].get_value(), this->world[c][r].get_reward()[next.get_state_number()] + this->world[c][r].get_discount()*next.get_value()));
						}
						break;
						
						case 'l':{
							next = this->world[c][r-1];
							this->world[c][r].set_value(std::max(this->world[c][r].get_value(), this->world[c][r].get_reward()[next.get_state_number()] + this->world[c][r].get_discount()*next.get_value()));
						}
						break;
						
						case 'r':{
							next = this->world[c][r+1];
							this->world[c][r].set_value(std::max(this->world[c][r].get_value(), this->world[c][r].get_reward()[next.get_state_number()] + this->world[c][r].get_discount()*next.get_value()));
						}
						break;
						
						default:{
						}
						break;
					}
				}
			}
		}
		
		g.world = a.world;
		a.world = this->world;
		itr++;
	}
}



