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

	while ((option = getopt(argc, argv, ":hdsc:" )) != -1) {
		switch(option) {
			case 'h': //help
				std::cout << "Help Message" << std::endl;
				exit(0);
			case 'd': //debug output
				//std::cout << D4_TOP << 4 << D4_BOTTOM << std::endl;
//				assignResult(1111);
//				for (int i = 0; i < 10; i++) {
//					std::cout << D4[i];
//					std::cout << D4[i];
//					std::cout << D6[i];
//					std::cout << D6[i];
//					std::cout << std::endl;
																														
//				}
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

	//loop through remaining non-option arguments
	int rollNum, diceSides;
	std::string diceString, sidesStr, rollStr;

	
	for (; optind < argc; optind++){ 
		diceString = argv[optind];

		rollStr = diceString.substr( 0, diceString.find( 'd' ) ); //get number before the 'd'
		sidesStr = diceString.substr( diceString.find( 'd' ) + 1 ); //get everything after the 'd'

		rollNum = std::stoi(rollStr);		//convert tokens to integers
		diceSides = std::stoi(sidesStr);

//		std::cout << diceSides << " sides : " << rollNum << " rolls" << std::endl;

		//addDice( rollNum, diceSides );
		add_dice( rollNum, diceSides );

		//TODO: Check if rollnum or rollsides is 0 before handing data to logic

	//	std::cout << diceSides << " sides : " << rollNum << " rolls" << std::endl;
		
	}
		draw_results( get_results() );
	//possible setup, send map to logic.cc -> logic.cc creates and returns a new vector of dice and their respective rolls 
	
}
