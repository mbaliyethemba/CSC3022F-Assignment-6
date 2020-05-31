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
	itrnum = itr;
	to_string(itr);
}

//print the grid function
void grid::to_string(int num){
	for(size_t i = 0; i < this->world.size(); i++){
		for(size_t j = 0; j < this->world[i].size(); j++){
			std::cout << "s" << this->world[i][j].get_state_number() << " : " << this->world[i][j].get_value() << " | ";
		}
		std::cout << '\n';
	}
	std::cout << "Iterations : " << num << std::endl;
}

//optimal policy function
void grid::optimal_policy(){
	state s = this->world[0][0];
	std::vector<char> act = s.get_action();
	state next_state;
	optimal_states.push_back(s);
	optimal_states_2.push_back(s);
	for(size_t a = 0; a < act.size() ; a++){
		switch (act[a]) {
			case 'r':{
                next_state=this->world[0][1];
                optimal_states.push_back(next_state);
                std::vector<char> act1 = next_state.get_action();
                std::vector<state> states;
                state c;
                for(char b : act1){
					switch(b){
						case 'l':{
							c = this->world[0][0];
							states.push_back(c);
						}
						break;
						
						case 'r':{
							c = this->world[0][2];
							states.push_back(c);
						}
						break;
						
						case 'd':{
							c = this->world[1][1];
							states.push_back(c);
						}
						break;
					}
				}
				next_state = optimal_state(states);
				optimal_states.push_back(next_state);
				states.erase(states.begin(), states.end());
				act1.erase(act1.begin(), act1.end());
				act1 = next_state.get_action();
				for(char b : act1){
					switch(b){
						case 'l':{
							c = this->world[1][0];
							states.push_back(c);
						}
						break;
						
						case 'r':{
							c = this->world[1][2];
							states.push_back(c);
						}
						break;
						
						case 'u':{
							c = this->world[0][1];
							states.push_back(c);
						}
						break;
					}
				}
				next_state = optimal_state(states);
				optimal_states.push_back(next_state);
				states.erase(states.begin(), states.end());
				act1.erase(act1.begin(), act1.end());
				act1 = next_state.get_action();
				switch(act1[0]){
					case 'u':{
						next_state = this->world[0][2];
						optimal_states.push_back(next_state);
					}
				}
				act1.erase(act1.begin(), act1.end());
				write_optimal(optimal_states);
              }
              break;
              
            case 'd':{
                next_state=this->world[1][0];
                optimal_states_2.push_back(next_state);
                std::vector<char> act1 = next_state.get_action();
                std::vector<state> states;
                state c;
                for(char b : act1){
					switch(b){
						case 'r':{
							c = this->world[1][1];
							states.push_back(c);
						}
						break;
						
						case 'u':{
							c = this->world[0][0];
							states.push_back(c);
						}
						break;
					}
				}
				next_state = optimal_state(states);
				optimal_states_2.push_back(next_state);
				states.erase(states.begin(), states.end());
				act1.erase(act1.begin(), act1.end());
				act1 = next_state.get_action();
				for(char b : act1){
					switch(b){
						case 'l':{
							c = this->world[1][0];
							states.push_back(c);
						}
						break;
						
						case 'r':{
							c = this->world[1][2];
							states.push_back(c);
						}
						break;
						
						case 'u':{
							c = this->world[0][1];
							states.push_back(c);
						}
						break;
					}
				}
				next_state = optimal_state(states);
				optimal_states_2.push_back(next_state);
				states.erase(states.begin(), states.end());
				act1.erase(act1.begin(), act1.end());
				act1 = next_state.get_action();
				switch(act1[0]){
					case 'u':{
						next_state = this->world[0][2];
						optimal_states_2.push_back(next_state);
					}
				}
				act1.erase(act1.begin(), act1.end());
				write_optimal(optimal_states_2);
              }
              break; 
		}
	}
}

state grid::optimal_state(std::vector<state> v){
	return v[v.size()-1];
}

void grid::write_optimal(std::vector<state> v){
	for(size_t i = 0; i < v.size()-1 ; i++){
		std::cout << "s" << v[i].get_state_number() << "->";
	}
	std::cout << "s" << v[v.size()-1].get_state_number() << std::endl;
}

//print out the answers to file
void grid::printAnswers(){
	std::ofstream ofs("Output Answers.txt");
	ofs << "Question 1" << '\n';
	for(size_t i = 0; i < this->world.size(); i++){
		for(size_t j = 0; j < this->world[i].size(); j++){
			ofs << "s" << this->world[i][j].get_state_number() << " : " << this->world[i][j].get_value() << " | ";
		}
		ofs << '\n';
	}
	ofs << "Iterations : " << itrnum << '\n';
	ofs << '\n';
	
	ofs << "Question 2" << '\n';
	for(size_t i = 0; i < optimal_states.size()-1 ; i++){
		ofs << "s" << optimal_states[i].get_state_number() << "->";
	}
	ofs << "s" << optimal_states[optimal_states.size()-1].get_state_number() << '\n';
	ofs << "or" << '\n';
	for(size_t i = 0; i < optimal_states_2.size()-1 ; i++){
		ofs << "s" << optimal_states_2[i].get_state_number() << "->";
	}
	ofs << "s" << optimal_states_2[optimal_states_2.size()-1].get_state_number() << '\n';
	ofs << '\n';
	
	ofs << "Question 3" << '\n';
	ofs << "Yes, If we change the immediate reward by multiplying it with a constant factor for example doubling each reward, the V* is also doubled, but π* remains unchanged." << '\n';
	ofs << "The optimal policy is calculated by the sequence of states with the highest utility." << '\n';
	ofs << "As long as the changes to the rewards are minor such that the state utility changes but the optimal sequence of states does not change the optimal policy will not change." << '\n';
}
