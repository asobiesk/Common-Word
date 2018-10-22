#ifndef STEP_H
#define STEP_H
#include <string>
using namespace std;

struct Step
{
    string word; //Word from alphabet {0,1,a} where 'a' means empty space
    int counter; //Number of word in given word list
    int position; //Number of position in word where we've added new character
    Step * prev; //Pointer to a previous position;
};




#endif // STEP_H
