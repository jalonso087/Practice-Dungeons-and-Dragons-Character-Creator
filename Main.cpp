/****************************************************
 * D&D Character Generator                          *
 * Javier Alonso                                    *
 * 2/15/2024 - 2/28/24                              *
 * v0.1                                            *
*****************************************************/
/////////////////////////////////////////////////////
//                      To-do
// /////////////////////////////////////////////////
//1. Add an if else block to race choice to prevent invalid numerical entries
//2. COMPLETE - Continue converting variables and functions to static where possible
//3. COMPLETE - Disable player choosing class that isn't shown on screen
//4. DROPPED  - Add pointers for function parameters
//5. COMPLETE - Add const to applicable variables
// -------------Meet with Nav-------------
//1. COMPLETE - Long-term: Move everything except main() to a different file(s) to avoid clutter

#include <iostream>
#include <random>
#include <string>
#include "character.h"


int main(void)
{   
    //for proper randomization in the random_num function calls
    srand(time(NULL));  

    std::cout << "Dungeons and Dragons Character Creator" << std::endl;

    //constructor parameter = character_level
    character player(1);

    print_character(player);

    std::cin.ignore();
    std::cin.get();

   // return 0;
}

void print_character(character player)
{

    std::cout
        << "\nHere's your character: \n\n"
        << "\nName: "
        << player.character_name
        << "\nLevel: "
        << player.character_level
        << "\nHP: "
        << player.hp
        << "\n---Stats---"
        << "\nStrength: "
        << player.statStr
        << "\nDexterity: "
        << player.statDex
        << "\nConstitution: "
        << player.statCon
        << "\nIntelligence: "
        << player.statInt
        << "\nWisdom: "
        << player.statWis
        << "\nCharisma: "
        << player.statCha
        << "\n----------\n"
        << "\nHappy Questing!\n\n";
}