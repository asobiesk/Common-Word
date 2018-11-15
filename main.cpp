#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>
#include <chrono>
#include <ctime>
#include "step.h"
#include "bruteforce.h"
#include "heuristic.h"
#include "wordlist.h"
#include "tests.h"

using namespace std;

void print_usage();
void help();


int main(int argc, char ** argv)
{
    if(!argv[1])
    {
        print_usage();
        return 0;
    }
    if( argc != 2 && argc != 4 && argc != 5 )
        {
            print_usage();
            return 0;
        }
    string arg1(argv[1]);

    if(arg1 == "-help")
    {
        help();
        return 0;
    }

    if(arg1 == "-compare")
        test_alghoritms(argv[2], stoi(argv[3]));

    if(arg1 == "-generate")
        generate_mode(argv[2], stoi(argv[3]), stoi(argv[4]));

    if(arg1 == "-test_word_number")
        test_word_number_mode(argv[2], stoi(argv[3]), stoi(argv[4]));

     if(arg1 == "-test_word_lenght")
       test_word_lenght_mode(argv[2], stoi(argv[3]), stoi(argv[4]));

     return(0);
}

void print_usage()
{
cout << "Usage: $ ./common_word [mode] [options]" << endl;
cout << "Example: $ ./common_word -generate 100 20 testFile" << endl;
cout << "For more info, type: $ ./common_word -help" << endl;
}

void help()
{
cout << "Usage: $ ./common_word [mode] [options]" << endl << endl;
cout << "----- Mode: Compare ------" << endl;
cout << "Usage: $ ./common_word -compare [filename] [word_lenght]" << endl;
cout << "Description: For an existing test instance (filename) program compares the results and time of bruteforce and heuristic alghoritm" << endl;
cout << "!!Please note that the word_lenght must be an integer between 1 and 20!!" << endl <<endl;
cout << "----- Mode: Generate ------" << endl;
cout << "Usage: $ ./common_word -generate [filename] [word_number] [word_lenght]" << endl;
cout << "Description: Program generates test file and uses heuristic alghoritm on it" << endl << endl;
cout << "----- Mode: Test Word Number------" << endl;
cout << "Usage: $ ./common_word -test_word_number [filename] [starting_word_number] [word_lenght]" << endl;
cout << "Description: Program generates 9 test files (word number increasing times 2 each time) and produces a table with complexity analysis" << endl << endl;
cout << "----- Mode: Test Word Lenght------" << endl;
cout << "Usage: $ ./common_word -test_word_lenght [filename] [word_number] [starting_word_lenght]" << endl;
cout << "Description: Program generates 9 test files (word lenght increasing times 2 each time) and produces a table with complexity analysis" << endl << endl;
}







