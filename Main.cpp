/****************************************************
 * D&D Character Generator                          *
 * Javier Alonso                                    *
 * 2/15/2024 - 2/21/24                              *
 * v0.03                                            *
*****************************************************/
/////////////////////////////////////////////////////
//                      To-do
// /////////////////////////////////////////////////
//1. Add an if else block to race choice to prevent invalid numerical entries
//2. Continue converting variables and functions to static where possible
//3. COMPLETE - Disable player choosing class that isn't shown on screen
//4. Long-term: Move everything except main() to a different file to avoid clutter

#include <iostream>
#include <random>
#include <string>

//using static prepend often since we do not need the linker to look for the variable/function definitions elsewhere

class character
{

private:

protected:

public:

    enum Race 
    {
        HUMAN = 1,
        ELF,
        DWARF,
        HALFLING
    };

    enum Class
    {
        WARRIOR = 1,
        THIEF,
        CLERIC,
        WIZARD
    };

    static int  character_level, 
                race, 
                player_class, 
                hp,
                statStr,
                statDex,
                statCon,
                statInt,
                statWis,
                statCha,
                die_method;
    
    static std::string character_name;

    static int random_num(int start, int max)
    {

        int random = start + rand() % (max);

        return random;

    }

    int stat_generator(void)
    {
        std::cout
            << "Which die rolling method would you like to use?"
            << std::endl;
        std::cout
            << "1. 3d6"
            << std::endl;
        std::cout
            << "2. 8+1d6"
            << std::endl;
        std::cout
            << "Selection: ";
        std::cin
            >> die_method;

        if (die_method == 1)
        {

            std::cout << "\nRolling 3d6 per stat..." << std::endl;

            statStr =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nStrength: "
                << statStr;

            statDex =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nDexterity: "
                << statDex;

            statCon =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nConstitution: "
                << statCon;

            statInt =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nIntelligence: "
                << statInt;

            statWis =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nWisdom: "
                << statWis;

            statCha =
                random_num(1, 6)
                + random_num(1, 6)
                + random_num(1, 6);

            std::cout
                << "\nCharisma: "
                << statCha;
        }
        else if (die_method == 2)
        {

            std::cout << "\nRolling 8+1d6 per stat..." << std::endl;

            statStr =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nStrength: "
                << statStr;

            statDex =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nDexterity: "
                << statDex;

            statCon =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nConstitution: "
                << statCon;

            statInt =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nIntelligence: "
                << statInt;

            statWis =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nWisdom: "
                << statWis;

            statCha =
                random_num(1, 6)
                + 8;

            std::cout
                << "\nCharisma: "
                << statCha;


        }
        return 0;
    }

    static int race_stat_changer(int race)
    {
        //int* ptrDex;
        //int* ptrCha;
        //int* ptrCon;
        //int* ptrStr;
        //int* ptrInt;
        //int* ptrWis;

        static int* ptrDex,
                  * ptrCha,
                  * ptrCon,
                  * ptrStr,
                  * ptrInt,
                  * ptrWis;

        std::cout
            << "Altering stats as necessary..."
            << std::endl;

        switch (race)
        {
        case(HUMAN):
            std::cout
                << "\nHumans require no stat changes."
                << std::endl;
            break;
        case(ELF):
            ptrDex = &statDex;
            ptrCha = &statCha;
            ptrCon = &statCon;
            std::cout
                << "\nElves require changes to Dexterity, Charisma, and Constitution."
                << std::endl
                << "Here are your new stats,\n\n"
                << "Dexterity: "
                << *ptrDex + 1
                << "\nCharisma: "
                << *ptrCha + 1
                << "\nConstitution: "
                << *ptrCon - 2;
            statDex += 1;
            statCha += 1;
            statCon -= 2;
            break;
        case(DWARF):
            ptrStr = &statStr;
            ptrCon = &statCon;
            ptrInt = &statInt;
            ptrCha = &statCha;
            std::cout
                << "\nDwarves require changes to Strength, Constitution, Intelligence, and Charisma."
                << std::endl
                << "Here are your new stats,\n\n"
                << "Strength: "
                << *ptrStr + 1
                << "\nConstitution: "
                << *ptrCon + 1
                << "\nIntelligence: "
                << *ptrInt - 1
                << "\nCharisma: "
                << *ptrCha - 1;
            statStr += 1;
            statCon += 1;
            statInt -= 1;
            statCha -= 1;
            break;
        case(HALFLING):
            ptrStr = &statStr;
            ptrDex = &statDex;
            std::cout
                << "\nHalflings require changes to Strength and Dexterity."
                << std::endl
                << "Here are your new stats,\n\n"
                << "Strength: "
                << *ptrStr - 2
                << "\nDexterity: "
                << *ptrDex + 2;
            statStr -= 2;
            statDex += 2;
            break;
        default:
            break;
        }
        return 0;
    }

    static int choose_class(void)
    {

        bool choosing = true;
        int choice;
        bool validWarrior = true;
        bool validThief = false;
        bool validCleric = false;
        bool validWizard = false;

        while (choosing)
        {
            std::cout
                << "\n\nWhich class would you like to be?\n"
                << "1. Warrior\n";
            if (statDex > 10)
            {
                validThief = true;
                std::cout
                    << "2. Thief\n";
            }

            if (statWis > 10 && statCha > 10)
            {
                validCleric = true;
                std::cout
                    << "3. Cleric\n";
            }

            if (statInt > 10)
            {
                validWizard = true;
                std::cout
                    << "4. Wizard\n";
            }

            std::cout
                << "Selection: ";

            

            std::cin >> choice;

            
             if (choice == THIEF && validThief == false)
            {
                std::cout
                    << "\n\nInvalid entry.\n"
                    << "Try again.\n\n";
            }
            else if (choice == CLERIC && validCleric == false)
            {
                std::cout
                    << "\n\nInvalid entry.\n"
                    << "Try again.\n\n";
            }
            else if (choice == WIZARD && validWizard == false)
            {
                std::cout
                    << "\n\nInvalid entry.\n"
                    << "Try again.\n\n";
            }
            else if (choice <= WIZARD && choice >= WARRIOR)
            {
                choosing = false;
                return choice;
            }
        }

    }

};

class classes : public character
{

private:

protected:

public:

};

class races : public character
{

private:

protected:

public:

};

    int character::character_level,
        character::race,
        character::player_class,
        character::hp,
        character::statStr,
        character::statDex,
        character::statCon,
        character::statInt,
        character::statWis,
        character::statCha,
        character::die_method;

    std::string character::character_name;






int choose_race(void)
{
    int choice;

    std::cout
        << "\n\nWhich race would you like to be?"
        << "\n1. Human"
        << "\n2. Elf"
        << "\n3. Dwarf"
        << "\n4. Halfling"
        << "\nSelection: ";

    std::cin >> choice;

    return choice;

}

int set_hp(int player_class)
{
    int hp_range;
    int hp;

    switch (player_class)
    {
    case(1):
        hp_range = 10;
        hp = character::random_num(1, hp_range);
        std::cout
            << "\nYou have "
            << hp
            << " hit points!\n";
        break;
    case(2):
        hp_range = 6;
        hp = character::random_num(1, hp_range);
        std::cout
            << "\nYou have "
            << hp
            << " hit points!\n";
        break;
    case(3):
        hp_range = 8;
        hp = character::random_num(1, hp_range);
        std::cout
            << "\nYou have "
            << hp
            << " hit points!\n";
        break;
    case(4):
        hp_range = 4;
        hp = character::random_num(1, hp_range);
        std::cout
            << "\nYou have "
            << hp
            << " hit points!\n";
        break;
    default:
        std::cout
            << "That's not a class.";
    }

    return hp;
}

std::string choose_character_name(void)
{
    std::string character;

    std::cout
        << "\nWhat first name will you give your character?\n\n"
        << "Name: ";

    std::cin >> character;

    return character;
}

void print_character(void)
{

    std::cout
        << "\nHere's your character: \n\n"
        << "\nName: "
        << character::character_name
        << "\nLevel: "
        << character::character_level
        << "\nHP: "
        << character::hp
        << "\n---Stats---"
        << "\nStrength: "
        << character::statStr
        << "\nDexterity: "
        << character::statDex
        << "\nConstitution: "
        << character::statCon
        << "\nIntelligence: "
        << character::statInt
        << "\nWisdom: "
        << character::statWis
        << "\nCharisma: "
        << character::statCha
        << "\n----------\n"
        << "\nHappy Questing!\n\n";

}

int main(void)
{   
    srand(time(NULL));  //for proper randomization in the random_num function calls

    std::cout << "Dungeons and Dragons Character Creator" << std::endl;

    character player;

    //std::string character_name;

    player.character_level = 1;
   
    player.stat_generator();

    player.race = choose_race();

    player.race_stat_changer(player.race);

    player.player_class = player.choose_class();

    player.hp = set_hp(player.player_class);

    player.character_name = choose_character_name();

    print_character();


    system("pause");

    return 0;
}