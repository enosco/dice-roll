#include <ctime>
#include <random>
#include "logic.hh"

std::vector<Die> diceData; 
int sum = 0;
int sum_mod = 0;

std::mt19937 mt(time(NULL)); // random number generator

// return random number between 1 - sides
int roll(int sides)
{
     std::uniform_int_distribution<> dist(1, sides);
     return dist(mt); 
}

// add dice to dollection
void add_dice(int numDice, int numSides, int mod)
{
     Die temp;
     for(; numDice > 0; numDice--) {
	  temp = {numSides, roll(numSides)+mod};
	  sum += temp.result;
	       
	  diceData.push_back(temp);
     }     
}

// return collection
std::vector<Die> get_dice()
{
     return diceData;
}

// set modifier to be added when get_sum() is called
void set_sum_modifier(int mod)
{
     sum_mod = mod;
}

// return sum
int get_sum()
{
     return sum + sum_mod;
}

    
