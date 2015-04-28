//Name: Danny Diep
//SID: 861146918
//Date: 4-20-2015
#include <iostream>
#include "lab3.h"
using namespace std;

int main()
{
    stack<int> A;
    stack<int> B;
    stack<int> C;
    for (int i = 0; i <3; i++)
    {
        A.push(i);
    }
    showTowerStates(3, A, B, C);
    // cout << "Stack 1 is empty: " << stack1.isEmptyStack1() << endl;
    // cout << "Stack 2 is empty: " << stack1.isEmptyStack2() << endl;
    // cout << "Stack 1 is full:" << stack1.isFullStack1() << endl;
    // cout << "Stack 2 is full:" << stack1.isFullStack2() << endl;
    
    
    
    
    return 0;
}