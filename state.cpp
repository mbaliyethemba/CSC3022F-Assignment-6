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

state::~state(){
}

//constructor
state::state(std::vector<char> action, std::map<int,int> reward, int val, int state_number, float discount, float probability){
	this->action = action;
	this->reward = reward;
	this->val = val;
	this->state_number = state_number;
	this->discount = discount;
	this->probability = probability;
}

//set methods for value, state number, discount and probability
void state::set_value(float value){
	this->val = value;
}

void state::set_state_number(int state_number){
	this->state_number = state_number;
}

void state::set_discount(float discount){
	this->discount = discount;
}

void state::set_probability(float probability){
	this->probability = probability;
}
