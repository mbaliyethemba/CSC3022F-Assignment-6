//Mbaliyethemba Shangase
//SHNMBA004
//Assignment 6
//29 May 2020

#include <vector>
#include <map>
#include <iostream>
#include "state.h"

state::state(){
}



state::state(std::vector<char> action, std::map<int,int> reward, int val, int state_number, float discount, float probability){
	this->action = action;
	this->reward = reward;
	this->val = val;
	this->state_number = state_number;
	this->discount = discount;
	this->probability = probability;
}
