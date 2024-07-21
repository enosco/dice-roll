/*#include "d4.hh"
#include "d6.hh"
#include "d8.hh"
#include "d10.hh"
#include "d12.hh"
#include "d20.hh"
*/
#include <string>

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

std::string D4_DEBUG = 
"0XXXXXXXXXXXXXXXXX20"
"1XXXXXXXXXXXXXXXXX20"
"2XXXXXXXXXXXXXXXXX20"
"3XXXXXX/^|\\XXXXXXX20"
"4XXXXX/   | \\XXXXX20"
"5XXXX/  #  |  \\XXX20"
"6XXX/       |  |XX20"
"7XX/_________|_|XX20"
"8XXXXXXXXXXXXXXXXX20"
"9XXXXXXXXXXXXXXXXX20";
//concerned with printing algorithm coming up short when printing escaped backslashes
//are lines 4-6 1 char short?
//if error comes up, try adding extra space to the end of these lines
//entire string should be 200 chars long?

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

/*
std::string D4[10] = {
"                   ",
"                   ",
"                   ",
"       /^|\\        ",
"      /   | \\      ",
"     /  " + result + "  |  \\    ",
"    /       |  |   ",
"   /_________|_|   ",
"                   ",
"                   ",
};

std::string D6[10] =
{
"                    ",
"      _________     ",
"    /________ /|    ",
"   |         | |    ",
"   |         | |    ",
"   |    " + result + "    | |    ",
"   |         | |    ",
"   |_________|/     ",
"                    ",
"                    ",
};*/
