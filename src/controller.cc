#include <iostream>
#include <unistd.h>
#include <string>
#include <unordered_map>
#include <set>
#include "diceroll.hh"
//#include "assets/dice_art.hh"

int main(int argc, char** argv) {

	// Take user input with options
		//-h for help
		//-c to add constant
			//notes about behavior:
				//most straightforward way is to add const to end overall result of sum, 
				//but what about when sum is not used, add to each roll? Sure.
				
		//-s print sum of all dice
		//example diceroll -s 1d8 2d6 -c 10 # roll 1 d8 and 2d6, then add 10 to sum

	if (argc == 1){
		std::cout << "Error: No arguments" << std::endl;
		exit(1);
	}

	int option;

	while ((option = getopt(argc, argv, ":hsc:" )) != -1) {
		switch(option) {
			case 'h': //help
				std::cout << "Help Message" << std::endl;
				exit(0);
			case 's': //sum
				break;
			case 'c': //add constant to roll
				break;
			case '?': //invalid option
				std::cout << "invalid option" << std::endl;
				break;
			default: //missing argument	
				std::cout << "missing arg" << std::endl;
				break;
		}
	}

	int rollNum, diceSides;
	std::string diceString, sidesStr, rollStr;

	//loop through remaining non-option arguments
	for (; optind < argc; optind++){ 
		diceString = argv[optind];

		rollStr = diceString.substr( 0, diceString.find( 'd' ) ); //get number before the 'd'
		sidesStr = diceString.substr( diceString.find( 'd' ) + 1 ); //get everything after the 'd'

		rollNum = std::stoi(rollStr);		//convert tokens to integers
		diceSides = std::stoi(sidesStr);

		add_dice( rollNum, diceSides );

		//TODO: Check if rollnum or rollsides is 0 before handing data to logic		
	}
	
		draw_results(get_results()); //send data from model to view for output formatting
}
