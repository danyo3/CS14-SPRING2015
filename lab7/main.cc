//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Danny Diep <ddiep003>
// SID: 861146918
// Date: May 11, 2015
// Lab 4
//  ================== END ASSESSMENT HEADER ===============
// bst.h
#include <cassert>
#include <iostream>
#include <fstream>
#include "lab7.h"
using namespace std;


int main()
{
    using namespace chrono;
    
    vector<string> word_bank;
    string input;
    ifstream inFS;
    
    inFS.open("words.txt");
    if (!inFS.is_open())
    {
        cout << "Erorr: Cannot open words.txt file." << endl;
        exit(-1);
    }
    
    while(inFS.good())
    {
        inFS >> input;
        word_bank.push_back(input);
    }
    inFS.close();
    
    scramble(word_bank);
    set<string> mySet;
    unordered_set<string> myUnSet;
    
    /*--------------- Insert Time for Set ---------------*/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for(unsigned i = 0; i < word_bank.size(); i++) mySet.insert(word_bank.at(i));
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

    /*--------------- Insert Time for Unordered_Set ---------------*/
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    for(unsigned i = 0; i < word_bank.size(); i++) myUnSet.insert(word_bank.at(i)); 
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration<double> time_span2 = duration_cast<duration<double> >(t4 - t3);
    
    ofstream outFS("data.txt");
    outFS << word_bank.size() << " ";
    outFS << time_span.count() << " ";
    outFS << time_span2.count() << " ";
    outFS << find_time_set(mySet, word_bank) << " ";
    outFS << find_time_unset(myUnSet, word_bank);
    
    return 0;
}