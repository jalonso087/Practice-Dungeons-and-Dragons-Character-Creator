#pragma once


class character
{

private:

    //unsigned char to use less memory
    const enum Race : unsigned char
    {
        HUMAN = 1,
        ELF,
        DWARF,
        HALFLING
    };

    //unsigned char to use less memory
    const enum Class : unsigned char
    {
        WARRIOR = 1,
        THIEF,
        CLERIC,
        WIZARD
    };

public:

    int character_level = 0,
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

    std::string character_name;

    character(const int starting_level)
    {
        character_level = starting_level;

        stat_generator();

        race = choose_race();

        race_stat_changer(race);

        player_class = choose_class();

        hp = set_hp(player_class);

        character_name = choose_character_name();
    }

    ~character()
    {
        std::cout << "Class destructing.";
    }

    static int random_num(const int start, const int max)
    {
        int random = start + rand() % (max);

        return random;
    }

    void stat_generator(void)
    {
        while (die_method != 1 && die_method != 2)
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

                std::cout << "\nStrength: " << statStr;

                statDex =
                    random_num(1, 6)
                    + random_num(1, 6)
                    + random_num(1, 6);

                std::cout << "\nDexterity: " << statDex;

                statCon =
                    random_num(1, 6)
                    + random_num(1, 6)
                    + random_num(1, 6);

                std::cout << "\nConstitution: " << statCon;

                statInt =
                    random_num(1, 6)
                    + random_num(1, 6)
                    + random_num(1, 6);

                std::cout << "\nIntelligence: " << statInt;

                statWis =
                    random_num(1, 6)
                    + random_num(1, 6)
                    + random_num(1, 6);

                std::cout << "\nWisdom: " << statWis;

                statCha =
                    random_num(1, 6)
                    + random_num(1, 6)
                    + random_num(1, 6);

                std::cout << "\nCharisma: " << statCha;
            }
            else if (die_method == 2)
            {

                std::cout << "\nRolling 8+1d6 per stat..." << std::endl;

                statStr = random_num(1, 6) + 8;

                std::cout << "\nStrength: " << statStr;

                statDex = random_num(1, 6) + 8;

                std::cout << "\nDexterity: " << statDex;

                statCon = random_num(1, 6) + 8;

                std::cout << "\nConstitution: " << statCon;

                statInt = random_num(1, 6) + 8;

                std::cout << "\nIntelligence: " << statInt;

                statWis = random_num(1, 6) + 8;

                std::cout << "\nWisdom: " << statWis;

                statCha = random_num(1, 6) + 8;

                std::cout << "\nCharisma: " << statCha;


            }
            else if (die_method < 1 || die_method > 2)
            {
                std::cout << "\nInvalid entry. Try again.\n";
            }
        }

    }

    void race_stat_changer(const int race)
    {
        int* ptrDex,
            * ptrCha,
            * ptrCon,
            * ptrStr,
            * ptrInt,
            * ptrWis;

        std::cout << "Altering stats as necessary..." << std::endl;

        switch (race)
        {
        case(HUMAN):
            std::cout << "\nHumans require no stat changes." << std::endl;
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

    }

    int choose_class(void)
    {

        bool choosing = true;
        bool validWarrior = true;
        bool validThief = false;
        bool validCleric = false;
        bool validWizard = false;
        int choice;

        while (choosing)
        {
            std::cout
                << "\n\nWhich class would you like to be?\n"
                << "1. Warrior\n";
            if (statDex > 10)
            {
                validThief = true;
                std::cout << "2. Thief\n";
            }

            if (statWis > 10 && statCha > 10)
            {
                validCleric = true;
                std::cout << "3. Cleric\n";
            }

            if (statInt > 10)
            {
                validWizard = true;
                std::cout << "4. Wizard\n";
            }

            std::cout << "Selection: ";

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
            else
            {
                std::cout
                    << "\n\nInvalid entry.\n"
                    << "Try again. \n\n";
            }
        }

    }

    int choose_race(void)
    {
        bool choosing = true;
        int choice;

        while (choosing)
        {
            std::cout
                << "\n\nWhich race would you like to be?"
                << "\n1. Human"
                << "\n2. Elf"
                << "\n3. Dwarf"
                << "\n4. Halfling"
                << "\nSelection: ";

            std::cin >> choice;

            if (choice < HUMAN)
            {
                std::cout << "\nInvalid entry. Try again.\n";
            }
            else if (choice > HALFLING)
            {
                std::cout << "\nInvalid entry. Try again.\n";
            }
            else  if (choice >= 1 && choice <= 4)
            {
                choosing = false;
                return choice;
            }

        }

    }

    int set_hp(const int player_class)
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

};