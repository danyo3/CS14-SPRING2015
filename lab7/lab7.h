//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Danny Diep <ddiep003>
// SID: 861146918
// Date: May 11, 2015
// Lab 4
//  ================== END ASSESSMENT HEADER ===============
// bst.h
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm> 
#include <chrono>
#include <ctime>
#include <ratio>

using namespace std;

double find_time_set(const set<string> &temp, const vector<string> &word);
double find_time_unset(const unordered_set<string> &temp, const vector<string> &word);
void scramble(vector<string>& word);



double find_time_set(const set<string> &temp, const vector<string> &word)
{
    using namespace chrono;
    high_resolution_clock::time_point t01 = high_resolution_clock::now();
    
    for(unsigned i = 0; i < word.size(); i++)
    {
        temp.find(word.at(i));
    }
    
    high_resolution_clock::time_point t02 = high_resolution_clock::now();
    duration<double> tot = duration_cast<duration<double> >(t02 - t01);
    return tot.count() / word.size();
}

double find_time_unset(const unordered_set<string> &temp, const vector<string> &word)
{
    using namespace chrono;
    high_resolution_clock::time_point t01 = high_resolution_clock::now();
    
    for(unsigned i = 0; i < word.size(); i++)
    {
        temp.find(word.at(i));
    }
    
    high_resolution_clock::time_point t02 = high_resolution_clock::now();
    duration<double> tot = duration_cast<duration<double> >(t02 - t01);
    return tot.count() / word.size();
}

void scramble(vector<string>& word)
{
    random_shuffle(word.begin(), word.end());
}