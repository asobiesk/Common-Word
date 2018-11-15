#ifndef WORDLIST_H
#define WORDLIST_H
#include <string>
#include <vector>
using namespace std;

string generate_word(int lenght);
vector<string> generate_list(int word_number, int lenght);
void generate_file(string filename, int word_number, int lenght);
vector<string> read_list(string filename);
bool compare_words(string w1, string w2);

#endif
