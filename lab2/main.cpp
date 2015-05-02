#include <iostream>
#include <typeinfo>
#include <iostream>
#include <string>
#include "lab2.h"
using namespace std;

int main()
{
    //LIST........................................................
    List<int> list;
    list.push(1);
    list.push(5);
    list.push(4);
    list.push(2);
    list.push(3);
    list.push(0);
    list.display();
    //LIST CONTENT: 1 5 4 2 3 0
    //............................................................
    
    //LIST CONTENT AFTER SWAP
    //1 5 4 3 2 0
    list.elementSwap(list, 3);
    list.display();
    //............................................................
    
    //FORWARD LIST TEST
    forward_list<int> l {1, 2 ,3};
    forward_list<int> p;
    //.................................................................
    
    
    //copy function..............................................
    listCopy(l , p);
    
    //Displays P
    for (auto it = p.begin(); it != p.end(); it++)
    {
        cout << *it << " ";
    }
    //..............................................................
    
    
    return 0;
}