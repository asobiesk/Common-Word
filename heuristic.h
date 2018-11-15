#ifndef HEURISTC_H
#define HEURISTIC_H
#include <string>
#include <vector>
#include "wordlist.h"
#include "step.h"
using namespace std;

string alghoritm_core(vector<string> word_list, int lenght);
string first_look(vector<string> word_list, int lenght);
string go_through_list(vector<string> word_list, string word, int lenght);

#endif
