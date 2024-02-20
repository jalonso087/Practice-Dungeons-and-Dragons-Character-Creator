/****************************************************
 * D&D Character Generator                          *
 * Javier Alonso                                    *
 * 2/15/2024                                        *
 * v0.01                                            *
*****************************************************/

#include <iostream>
#include <random>
#include <Windows.h>

class character
{

private:

protected:

public:
    int character_level = 1;

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

int die_method;
int statStr;
int statDex;
int statCon;
int statInt;
int statWis;
int statCha;

int random_num(int start, int max)
{
    
    int random = start + rand() % (max);

    return random;

}

int stat_generator(void)
{
    std::cout << "Which die rolling method would you like to use?" << std::endl;
    std::cout << "1. 3d6" << std::endl;
    std::cout << "2. 8+1d6" << std::endl;
    std::cout << "Selection: ";
    std::cin >> die_method;

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

int race_stat_changer(int race)
{
    int* ptrDex;
    int* ptrCha;
    int* ptrCon;
    int* ptrStr;
    int* ptrInt;
    int* ptrWis;
    

    std::cout
        << "Altering stats as necessary..."
        << std::endl;

    switch (race)
    {
    case(1):
        std::cout
            << "\nHumans require no stat changes."
            << std::endl;
        break;
    case(2):
        ptrDex = &statDex;
        ptrCha = &statCha;
        ptrCon = &statCon;
        std::cout
            << "\nElves require changes to Dexterity, Charisma, and Constitution."
            << std::endl
            << "Here are your new stats,\n"
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
    case(3):
        ptrStr = &statStr;
        ptrCon = &statCon;
        ptrInt = &statInt;
        ptrCha = &statCha;
        std::cout
            << "\nDwarves require changes to Strength, Constitution, Intelligence, and Charisma."
            << std::endl
            << "Here are your new stats,\n"
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
    case(4):
        ptrStr = &statStr;
        ptrDex = &statDex;
        std::cout
            << "\nHalflings require changes to Strength and Dexterity."
            << std::endl
            << "Here are your new stats,\n"
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

int main(void)
{   

    srand(clock());

    std::cout << "Dungeons and Dragons Character Creator" << std::endl;
    //code starts here
    stat_generator();
    int race = choose_race();
    race_stat_changer(race);

    return 0;
}