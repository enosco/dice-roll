#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

/* for logic.cc */
struct die { //contains data for a single die
	int sides;
	int result;
	//std::string graphic[10];
    std::string graphic;
};

void add_dice(int numDice, int numSides); //add dice to vector
std::vector<die> get_results();		      //return contents of vector 
void print_raw_data();                    //print contents of vector for debugging

/* for view.cc */
void draw_results(std::vector<die> data); //print ascii art, results, and sum
