#include "tests.h"

void test_word_number_mode(string filename, int word_number, int lenght)
{
vector<long int> sizes;
vector<double> times;
vector<double> q;

for(int i=0; i<9; ++i)
{
    generate_file(filename, word_number, lenght);
    vector<string> word_list = read_list(filename);
    auto start = chrono::system_clock::now();
    string result = alghoritm_core(word_list, lenght);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;

    sizes.push_back(word_number);
    times.push_back(elapsed_seconds.count());

    word_number *= 2;
}

for(int i=0; i<9; ++i)
{
    double currentq = (times[i] * pow(sizes[4], 1))/(times[4]* pow(sizes[i], 1));

    q.push_back(currentq);

}
print_table(sizes, times, q);
}

long long int silnia(long int n)
{
long long silnia = 1;

for(int i=n; i>1; --i)
    silnia *= i;

return silnia;
}

void test_word_lenght_mode(string filename, int word_number, int lenght)
{
vector<long int> sizes;
vector<double> times;
vector<double> q;

for(int i=0; i<9; ++i)
{
    generate_file(filename, word_number, lenght);
    vector<string> word_list = read_list(filename);
    auto start = chrono::system_clock::now();
    string result = alghoritm_core(word_list, lenght);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;

    sizes.push_back(lenght);
    times.push_back(elapsed_seconds.count());

    lenght *= 2;
}

for(int i=0; i<9; ++i)
{
    double currentq = (times[i] * pow(sizes[4], 1))/(times[4]* pow(sizes[i], 1));

    q.push_back(currentq);

}
print_table(sizes, times, q);
}

void print_table(vector<long int> sizes, vector<double> times, vector<double> q)
{

    for(int i = 0; i<9; ++i)
    {
    cout << sizes[i] << "           " << times[i] << "          " << q[i] << endl;
    }

}

void generate_mode(string filename, int word_number, int lenght)
{
    generate_file(filename, word_number, lenght);
    vector<string> word_list = read_list(filename);
    chrono::duration<double> heuristic_result = test_heuristic(word_list, lenght);
     cout << "Elapsed time (s): " << heuristic_result.count() << endl;
}

void test_alghoritms(string filename, int lenght)
{

    vector<string> word_list = read_list(filename);
    if(word_list.empty())
    {
    cout << "Cannot open the file";
    return;
    }

    cout << "Bruteforce test: " << endl;
    chrono::duration<double> brute_result = test_bruteforce(word_list, lenght);
    cout << "Elapsed time (s): " << brute_result.count() << endl << endl;

    cout << "Heuristic test: " << endl;
    chrono::duration<double> heuristic_result = test_heuristic(word_list, lenght);
    cout << "Elapsed time (s): " << heuristic_result.count() << endl << endl;


}

chrono::duration<double> test_bruteforce(vector<string> word_list, int lenght)
{
    vector<string> all_words = generate_all_words(lenght);
    auto start = chrono::system_clock::now();
    string result = brute_force(word_list, all_words, lenght);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;
    cout << "Solution: " << result << endl;
    return elapsed_seconds;
}

chrono::duration<double> test_heuristic(vector<string> word_list, int lenght)
{
    auto start = chrono::system_clock::now();
    string result = alghoritm_core(word_list, lenght);
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end1-start;
    cout << "Solution: " << result << endl;
    return elapsed_seconds;
}


