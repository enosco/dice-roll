#include "diceroll.hh"	
#include "assets/dice_art.hh"

/*Replaces placeholder "#" in ascii art with result of die*/
std::string insert_result(std::string dieArt, int result){
	int index = dieArt.find("#");
	int digits = 1; //num digits to replace

	std::string resultString = std::to_string(result);

	//insert a space between double digits for better formatting
	if(result > 9){
		resultString.insert(1, " ");
		digits = 3;	
		index--;	
	}

	dieArt.replace(index, digits, resultString);

	return dieArt;
}

/*Returns completed ascii art and result according to number of sides

  TODO: Handle dice with non-standard number of sides;
  		Currently outputs debug grid  		
*/

std::string create_die_art(die d){

	std::string dieArt;
	//int index;
	
	switch(d.sides){
		case 4:
			dieArt = D4;
			break;
		case 6:
			dieArt = D6;
			break;
		case 8:
			dieArt = D8;
			break;
		case 10:
			dieArt = D10;
			break;
		case 12:
			dieArt = D12;
			break;
		case 20:
			dieArt = D20;
			break;
		default:
			dieArt = DEFAULT;
	}
	
	return insert_result(dieArt, d.result);
}


/*Formats and prints output of dice results in 4-column wide grid*/
void draw_results(std::vector<die> data){

	//later, consolidate output.size into single SIZE var

	//vector containing ascii art of each die in data
	std::vector<std::string> output;

	for( die d : data){
		output.push_back(create_die_art(d));
	}

	//place this next logic in its own function to clean things up

	//upper & lower determine the interval of indicies to print
	int lower_limit = 0;
	int upper_limit = 4;

	bool diceLeft = true;
	while(diceLeft){

		int offset = 0;

		//outer loop repeats for each line in the ascii art
		for(int i = 0; i < 10; i++){

			/*inner loop prints a single line of art for dice within the interval
		      while offset determines which line is printed*/
			for(int j = lower_limit; j < upper_limit && j < (int)output.size(); j++){

				std::cout << output[j].substr(0+offset, 20); 
				/*substr behavior: substr(pos,len)
				    pos: beginning index
					len: num of chars to include, NOT ending index*/
					
			}
			
		std::cout << std::endl;

		//ascii art has 20 chars per row, adding 20 shifts to next row
		offset += 20;

		}

		//shift interval by 4 to begin printing new row
		lower_limit += 4;
		upper_limit += 4;

		//this should stop the loop when the upper limit exceeds the number of dice rolled
		//3 seems to be the sweet spot where no dice are skipped AND no extra spaces are added
		if(upper_limit > (int)output.size() + 3){
			diceLeft = false;
		}
	}

}
