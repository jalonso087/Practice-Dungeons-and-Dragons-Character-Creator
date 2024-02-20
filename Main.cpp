/****************************************************
 * D&D Character Generator                          *
 * Javier Alonso                                    *
 * 2/15/2024                                        *
 * v0.01                                            *
*****************************************************/

#include <iostream>
#include <random>



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

int statGenerator(void)
{
    std::cout << "Which die rolling method would you like to use?" << std::endl;
    std::cout << "1. 3d6" << std::endl;
    std::cout << "2. 8+1d6" << std::endl;
    std::cout << "Selection: ";
    std::cin >> die_method;

    if (die_method == 1)
    {

        std::cout << "Rolling 3d6 per stat..." << std::endl;
        //statStr = 

    }
    return 0;
}

int random_num(int start, int max)`
{
    clock_t current_time = clock();
    srand ((unsigned)clock());

    int random = start + rand() % (max);

    return random;

}

int random_1to6 = 1 + rand() % 9;

int main(void)
{
    std::cout << "Dungeons and Dragons Character Creator" << std::endl;
    //code starts here
    std::cout << random_num(1, 6) << " " << random_num(1,6) << " " << random_num(1,6);
    return 0;
}