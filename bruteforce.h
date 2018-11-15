#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include "wordlist.h"
using namespace std;

string brute_force(vector<string> word_list, vector<string> all_words, int lenght);
vector<string> generate_all_words(int length);

#endif
