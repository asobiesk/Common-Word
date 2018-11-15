#include "bruteforce.h"


//Find solution using bruteforce alghoritm
string brute_force(vector<string> word_list, vector<string> all_words, int length)
{

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

    if(result.size() == 0)
        result = "No solution exists!";
    return result;
}

//generate every binary word of lenght n
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


