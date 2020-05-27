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

//print out the iteration
void grid::printGrid(int num){
	for(int i = 0; i < num ; i++){
		
	}
}

//optimal policy function
std::vector<state> grid::optimal_policy(state s){
	std::vector<state> states, optimal_states;
	state next_state;
	optimal_states.push_back(s);
	this->world[0][2].set_value(FLT_MAX);
	for(size_t c = 0; c < this->world.size(); c++){
		for(size_t r = 0; r < this->world[c].size(); r++){
			if(s.get_state_number() == this->world[c][r].get_state_number()){
				while(s.get_state_number() != 3){
					for(char a: s.get_action()){
						switch(a){
							case 'u': {
								next_state = this->world[c-1][r];
								states.push_back(next_state);
							}
							break;
							
							case 'd': {
								next_state = this->world[c+1][r];
								states.push_back(next_state);
							}
							break;
							
							case 'l': {
								next_state = this->world[c][r-1];
								states.push_back(next_state);
							}
							break;
							
							case 'r': {
								next_state = this->world[c][r+1];
								states.push_back(next_state);
							}
							break;
							
							case 'i': {
								next_state = this->world[c][r];
								states.push_back(next_state);
							}
							break;
							
							default: {
							}
							break;
						}
					}
					s = optimal_state(states);
					optimal_states.push_back(s);
					states.erase(states.begin(), states.end());
				}
			}
		}
	}
	return optimal_states;
}

state grid::optimal_state(std::vector<state> v){
	state s;
	for(size_t c = 0; c < v.size(); c++){
		if(v[c].get_value() > s.get_value()){
			s.set_value(v[c].get_value());
			s.set_state_number(v[c].get_state_number());
		}
	}
	return s;
}
