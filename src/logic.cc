/*#include <random>
#include <ctime>
#include <vector>
#include <iostream>*/
#include "diceroll.hh"

struct die;

std::vector<die> diceData;
std::mt19937 mt( time ( NULL ) );

int roll( int sides ) {
	//TODO: Complete random number generator, research mt19937
	std::uniform_int_distribution<> dist(1, sides);
	return dist(mt); 	
}

void add_dice( int numDice, int numSides ) {
	for (; numDice > 0 ; numDice-- ) {
		diceData.push_back( {.sides = numSides, .result = roll(numSides)} ); 

	}
}

std::vector<die> get_results(){ //TODO: Later, include sum with this data
    return diceData;
}



void print_raw_data(){

	for ( die elem : diceData ){
		//std::cout << "Rolled a d" << elem.sides << " and got a " << elem.result << std::endl;
		std::cout << elem.result << std::endl;
	}
}

//TODO: Create method for calculating sum
