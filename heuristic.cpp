#include "heuristic.h"

string alghoritm_core(vector<string> word_list, int lenght)
{

string result = first_look(word_list, lenght);

if(result == "END")
    return "No solution exists!";

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
            if(word[i] == 'a')      //when you find blank space...
            {
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
