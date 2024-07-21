//TODO: Grab data from vector in logic.cc
	//create ascii art and format output
#include "diceroll.hh"	
#include "assets/dice_art.hh"


/*void update_result(int nextResult){
	result = nextResult;
}*/

//TODO: figure out how to print out 4 columns of dice per row
//potential method:
	//two for loops that prints each die out line by line
	//OR: bind art to each die in the struct, use switch statement there to determine
	// art to use, then concat with known result
	//OR: use a temp array and counter; create array of 4 dice,  increasing counter each loop, then
	// print and reset counter
			//use line by line approach here too 


std::string create_die_art(die d){

	std::string dieArt;
	int index;
	
	switch(d.sides){
		case 4:
			dieArt = D4;
			index = dieArt.find("#"); //will crash if no index is found, fix this
			dieArt.replace(index, 1, std::to_string( d.result ) );
			break;
		case 6:
			break;
		case 8:
			break;
		case 10:
			break;
		case 12:
			break;
		case 20:
			break;
		default:
			dieArt = DEBUG_GRID;
	}

	
	
	return dieArt;
}

/*void print_row(std::string* arr){
	for(int i = 0; i < 3; i++){
		std::cout << arr[i] << std::endl;
	}
}*/

//print first 20 characters of each dice, then next 20, then next 20

void draw_results(std::vector<die> data){

	/*for( die d : data){
		d.graphic = create_die_art(d);
	}*/

	//std::vector<std::string> output;
	for(int i = 0; i < (int)data.size(); i++){		
	}

	std::vector<std::string> output;
	for( die d : data){
		output.push_back(create_die_art(d));
	}

	int offset = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < (int)output.size(); j++){

		//	std::cout << output[j].substr(0+offset, 20+offset);
			std::cout << output[j].substr(0+offset, 20); 
			/*substr behavior: substr(pos,len)
				pos: beginning index
				len: num of chars to include, NOT ending index */
		}

		std::cout << std::endl;

		offset += 20;
		
		/*if(offset > 200){
			offset = 0;

		}*/
		//std::cout << output[i] << std::endl;
	}
}



/*switch(d.sides){
			case 4:
				break;
			case 6:
				break;
			case 8:
				break;
			case 10:
				break;
			case 12:
				break;
			case 20:
				break;
		}*/
