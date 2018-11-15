#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "wordlist.h"

//--------<Generator>-----------

//Generate file for test data
void generate_file(string filename, int word_number, int lenght)
{
    fstream file;
    vector<string> word_list = generate_list(word_number, lenght);
    vector < string >::iterator it = word_list.begin();
    file.open(filename, ios::out);

    if(!file.good()){
        cout << "Problem";
        return; }

    for(; it != word_list.end(); it++ )
            file <<* it << endl;

}

//Generate list of random words for testing purposes
vector<string> generate_list(int word_number, int lenght)
{
    vector<string> word_list;
     srand(time(0));


    for(int i=0; i<word_number; ++i)
    {
        word_list.push_back(generate_word(lenght));
    }

    return word_list;
}

//Generate random word
string generate_word(int lenght)
{
    static const char alphabet[]  = "01*";
    string word;

    for(int i = 0; i<lenght; ++i)
    {
     word += alphabet[rand() % 3];
    }

    return word;
}

//----------</Generator>---------------

//Read list from a file
vector<string> read_list(string filename)
{
    fstream file;
    string word;
    vector<string> word_list;
    file.open( filename, std::ios::in );

    if(!file.good())
        return word_list;


    while(!file.eof())
    {
        getline(file, word);
        if(!word.length() == 0)
            word_list.push_back(word);
    }
    return word_list;
}

//Compare two words looking for a match at any position
bool compare_words (string word1, string word2)
{
  for(int i=0; i<word1.length(); ++i)
  {
    if(word1[i] == word2[i])
        return true;
  }
  return false;
}
