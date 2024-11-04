#include <vector>
#include "die.hh"
/*struct Die {
     int sides;
     int result;
     };*/

void add_dice(int numDice, int numSides, int mod);
void set_sum_modifier(int mod);
//void set_die_modifier(int modifier) // unnecessary if roll constants are handled during input
std::vector<Die> get_dice(); 
int get_sum();


