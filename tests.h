#ifndef TESTS_H
#define TESTS_H
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include "bruteforce.h"
#include "heuristic.h"
using namespace std;

void test_alghoritms(string filename, int lenght);
chrono::duration<double> test_bruteforce(vector<string> word_list, int lenght);
chrono::duration<double> test_heuristic(vector<string> word_list, int lenght);
void generate_mode(string filename, int word_number, int lenght);
void test_word_number_mode(string filename, int word_number, int lenght);
void test_word_lenght_mode(string filename, int word_number, int lenght);
void print_table(vector<long int> sizes, vector<double> times, vector<double> q);
long long int silnia(long n);
#endif
