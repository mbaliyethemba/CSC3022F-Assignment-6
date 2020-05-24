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

//get methods for discount, probability, state number, probability, reward, value, action
float state::get_discount(){
	return this->discount;
}

float state::get_probability(){
	return this->probability;
}

std::map<int, int> state::get_reward(){
	return this->reward;
}

int state::get_state_number(){
	return this->state_number;
}

float state::get_value(){
	return this->val;
}

std::vector<char> state::get_action(){
	return this->action;
}

//printing methods
void state::to_string(){
	for(size_t i = 0; i < this->action.size(); i++){
		std::cout << this->action[i] << " " <<'\n';
	}
	
	for(size_t i = 0; i < this->action.size(); i++){
		std::cout << this->reward[i] << " " << '\n';
	}
	
	std::cout << "Value : " << this->val << std::endl;
	std::cout << "State Number : " << this->state_number << std::endl;
	std::cout << "Discount : " << this->discount << std::endl;
	std::cout << "Probability : " << this->probability << std::endl;
	
}
