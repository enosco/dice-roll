#include <iostream>
#include <unistd.h>
#include <string>
#include <queue>
#include "logic.hh"
#include "view.hh"
#include "die.hh"

void print_help();

int main(int argc, char** argv)
{

     if (argc == 1) {
	  std::cout << "Error: No arguments" << std::endl;
	  exit(1);
     }
     
     bool sum_flag = false;
     
     int option;     
     while ((option = getopt(argc, argv, ":hsm:" )) != -1) {
	  switch (option) {
	  case 'h': // print help message
	       print_help();
	       exit(0);
	  case 's': // toggle sum flag 
	       sum_flag = true;
	       break;
	  case 'm': // add modifier to roll
	       set_sum_modifier(std::stoi(optarg));
	       break;
	  case ':':
	       std::cout << "missing argument for option " + optopt << std::endl;
	  case '?': // invalid option
	       std::cout << "invalid option" << std::endl;	       
	       break;
	  default: // missing argument	
	       std::cout << "missing arg" << std::endl;
	       break;
	  }
     }
     
     // parse remaining non-option args
     int amount, sides, modifier = 0;
     std::string dice_str, amount_str, sides_str;

     std::size_t delim_pos;
     char delim_char;     
     for (; optind < argc; optind++) { 	
	  dice_str = argv[optind];
	  
	  delim_pos = dice_str.find("d");
	  if (delim_pos == std::string::npos) {
	       // handle malformed dice string error
	       std::cout << "malformed dice string -- use -h for usage details" << std::endl;
	       exit(1);
	  }
	  
	  amount = std::stoi(dice_str.substr(0, delim_pos)); // store amount of dice to be rolled
	  sides_str = dice_str.substr(delim_pos+1);
	  
	  std::cout << sides_str << " sides_str" << std::endl;
	  
	  // consider splitting this into ites own function

	  delim_pos = sides_str.find_first_not_of("0123456789");
	  
	  if (delim_pos == std::string::npos) {
	       sides = std::stoi(sides_str);
	  } else {
	       delim_char = sides_str.at(delim_pos);
	       
	       if (delim_char == '+' || delim_char == '-') {
		    sides = std::stoi(sides_str.substr(0, delim_pos));	       
		    modifier = std::stoi(sides_str.substr(delim_pos+1));
		    
		    if (delim_char == '-') {
			 modifier *= -1;
		    }		    
	       } else {		    
		    std::cout << "malformed dice string -- use -h for usage details" << std::endl;
		    exit(1);
	       }
	  }
	  
	  
	  add_dice(amount, sides, modifier); // send data to model
	  amount = sides = modifier = 0;
     }
         	
     draw_results(get_dice()); //send data from model to view for output formatting

     if(sum_flag) {
	  print_sum(get_sum());
     }
}

void print_help() {
     std::cout << "Usage: diceroll [OPTIONS] [X]d[Y]+[C]..." << std::endl;
     std::cout << "Rolls and displays the results of x[X]d[Y]+[C] dice" << std::endl;
     std::cout << "  X\tamount of dice" << std::endl;
     std::cout << "  Y\tnumber of sides" << std::endl;
     std::cout << "  C\tmodifier to add to roll(s) -- may be positive or negative" << std::endl;
     std::cout << "Example: diceroll 2d6 8d12+5 2d20-2" << std::endl;
     std::cout << "\noptions:" << std::endl;
     std::cout << "  -s\tdisplay sum of all dice" << std::endl;
     std::cout << "  -m\tspecify modifier to add to sum" << std::endl;  
}
     
