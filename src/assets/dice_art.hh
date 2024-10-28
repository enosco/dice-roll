#include <string>

/*An extra space must be included after each
  escaped backslash so everything lines up
  correctly*/

//All art is standardized to have 20 columns & 10 rows

std::string D4 = 
"                    "
"                    "
"                    "
"       /^|\\         "
"      /   | \\       "
"     /  #  |  \\     "
"    /       |  |    "
"   /_________|_|    "
"                    "
"                    ";

std::string D6 =
"                    "
"      _________     "
"    /________ /|    "
"   |         | |    "
"   |         | |    "
"   |    #    | |    "
"   |         | |    "
"   |_________|/     "
"                    "
"                    ";

std::string D8 =
"                    "
"       /|\\          "
"     / | | \\        "
"   /  |   |  \\      "
"  |  |  #  |  |     "
"  | |       | |     "
"  ||_________||     "
"   \\         /      "
"      \\   /         "
"                    ";

std::string D10 =
"                    "
"        /|\\         " 
"      / | | \\       "
"    /  |   |  \\     "
"  /   |  #  |   \\   "
" <  _|       |_  >  "
"  \\/   \\   /   \\/   "
"    \\    |    /     "
"      \\  |  /       "
"        \\|/         ";

std::string D12 =
"                    "
"     . //^\\\\ .      "
"   /     |     \\    "
"  |     /^\\     |   "
"  |\\_ /     \\ _/|   "  
"  |  |   #   |  |   "
"  |   |_____|   |   "
"   \\ /       \\ /    "
"     \\\\  .  //      "
"                    ";

std::string D20 =
"                    "
"      /  ^  \\       "
"   /_____|_____\\    "
"  ||    /^\\    ||   "
"  | |  / # \\  | |   "
"  |  |/_____\\|  |   "
"  |  /\\     / \\ |   "
"   \\   \\   /   /    "
"     \\ _\\./_ /      "
"                    ";

//Use for dice without art
std::string DEFAULT = 
"                    "
"                    "
"                    "
"                    "
"   DIE RESULT: #    "
"                    "
"                    "
"                    "
"                    "
"                    ";

std::string DEBUG_GRID = 
"0XXXXXXXXXXXXXXXXX20"
"1XXXXXXXXXXXXXXXXX20"
"2XXXXXXXXXXXXXXXXX20"
"3XXXXXXXXXXXXXXXXX20"
"4XXXXXXXXXXXXXXXXX20"
"5XXXXXXXXXXXXXXXXX20"
"6XXXXXXXXXXXXXXXXX20"
"7XXXXXXXXXXXXXXXXX20"
"8XXXXXXXXXXXXXXXXX20"
"9XXXXXXXXXXXXXXXXX20";
