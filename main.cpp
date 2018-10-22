#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>
#include <chrono>
#include <ctime>
#include "step.h"

using namespace std;

string generate_word(int lenght);
vector<string> generate_list(int word_number, int lenght);
void generate_file(string filename, int word_number, int lenght);
vector<string> read_list(string filename);
string brute_force(vector<string> word_list, int lenght);
vector<string> generate_all_words(int length);
bool compare_words(string w1, string w2);

string alghoritm_core(vector<string> word_list, int lenght);
string first_look(vector<string> word_list, int lenght);
string go_through_list(vector<string> word_list, string word, int lenght);

int main()
{
    int liczba_slow = 100;
    int liczba_liter = 30;
    string result;
    generate_file("test_asterisk", liczba_slow, liczba_liter);
    vector<string> word_list = read_list("test_asterisk");
    //string result;
    if(word_list.empty())
        return 0;
    //cout << alghoritm_core(word_list, 7);



    /*
    cout << "Test bruteforce'a: " << endl;
    auto start = chrono::system_clock::now();
    result = brute_force(word_list, liczba_liter);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;
    cout << "Solution: " << result << endl;
    cout << " Time: " << elapsed_seconds.count() << endl;
    */
    cout << "Test mojego algosa: " << endl;
    auto start = chrono::system_clock::now();
    result = alghoritm_core(word_list, liczba_liter);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;
    cout << "Solution: " << result << endl;
    cout << " Time: " << elapsed_seconds.count() << endl;




    return 0;
}

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

string generate_word(int lenght)
{
    static const char alphabet[]  = "01******";
    string word;

    for(int i = 0; i<lenght; ++i)
    {
     word += alphabet[rand() % 8];
    }

    return word;
}

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

vector<string> generate_all_words(int n)
{

    queue<string> q;
    vector<string> word_list;
    //generete first word: 000...0
    string first_word;
    for(int i =0; i<n; ++i)
        first_word += "0";
    word_list.push_back(first_word);
    q.push("1");
    long counter = pow(2, n) - 1;
    while (counter--)
    {
        string s1 = q.front();
        q.pop();
        string word = s1;

        for(int i=0;i=(n-word.size()); ++i)
            word = "0" + word;

        word_list.push_back(word);

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    return word_list;
}

string brute_force(vector<string> word_list, int length)
{
    vector<string> all_words = generate_all_words(length);
    vector < string >::iterator it_all_words = all_words.begin();
    vector < string >::iterator it_word_list = word_list.begin();
    string result;
    int counter = 0;
    bool flag = true;
    for(; it_all_words != all_words.end(); ++it_all_words)
    {
        flag = true;
        it_word_list = word_list.begin();
        for(; it_word_list != word_list.end(); ++it_word_list)
        {
            ++counter;
            if(!compare_words(*it_word_list, *it_all_words))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            result = *it_all_words;
            break;
        }
    }
    cout << "Counter: "  << counter << endl;
    return result;
}

bool compare_words (string word1, string word2)
{
  for(int i=0; i<word1.length(); ++i)
  {
    if(word1[i] == word2[i])
        return true;
  }
  return false;
}

// ***************************** Algorytm wlasciwy ********************************************

string alghoritm_core(vector<string> word_list, int lenght)
{

string result = first_look(word_list, lenght);

if(result == "END")
    return "END";

cout << "Po pierwsxzym kroku: " << result << endl;
result = go_through_list(word_list, result, lenght);
return result;
}

string first_look(vector<string> word_list, int lenght)
{
    vector < string >::iterator it = word_list.begin();
    int non_asterisk_counter = 0;
    int non_asterisk_position = -1;
    string result;

    for(int i=0;i<lenght;++i)
        result += 'a';

    for(; it!=word_list.end(); ++it)
    {
        non_asterisk_counter = 0;
        non_asterisk_position = -1;

        for(int i=0; i<lenght; ++i)
        {
            if((*it)[i] != '*')
            {
                ++non_asterisk_counter;
                non_asterisk_position = i;
            }
        }

        if(non_asterisk_counter == 0)
            return "END";

        if(non_asterisk_counter == 1)
        {
            if(result[non_asterisk_position] != 'a' && result[non_asterisk_position] != (*it)[non_asterisk_position])
                return "END";
            result[non_asterisk_position] = (*it)[non_asterisk_position];
        }
    }
    return result;
}

string go_through_list(vector<string> word_list, string word, int lenght)
{
    vector < string >::iterator it = word_list.begin();
    Step * help_list_front;
    int counter = -1;
    int position = 0;
    bool flag = false;

    for(; it!=word_list.end(); ++it) //take next word from word list
    {
        if(compare_words(word, *it))
        {
            position = 0;
            continue;               //if there is any match, go to next word
        }
        //Step 3 from alghoritm description
        for(int i=position; i<lenght; ++i) //go throgh chars in our result word
        {
            ++counter;
            flag = false;
            cout << "dodaje cos" << endl;
            if(word[i] == 'a')      //when you find blank space...
            {
                cout << "znalazlem a" << endl;
                if((*it)[i] == '*')
                    continue;       //...if it is * in word from list, go next

                //cout << "dodaje step" << endl;
                Step new_step;      //...if it isn't create Step structure
                new_step.word = word;
                new_step.counter = counter;
                new_step.position = i;
                new_step.prev = help_list_front;
                help_list_front = &new_step;
                word[i] = (*it)[i];
                position = 0;
                flag = true;

                cout << "po dodaniu: " << word << endl;
                break;          //go again through the list
            }
        }
    if(flag) continue;
    //Step 4 from alghoritm description
    //cout << "jestesmy w krok 4" << endl;
    if(!help_list_front)    //if there is no help list yet
        return "END";   //there is no solution
    if(help_list_front->counter == counter)
    {
        if(!help_list_front->prev)
            return "END";
        Step * tmp = help_list_front->prev;
        //delete help_list_front;
        help_list_front = tmp;
    }
    word = help_list_front->word;
    counter = (help_list_front->counter)-1;
    position = help_list_front->position;
    it = word_list.begin() + counter;


    }
return word;

}
