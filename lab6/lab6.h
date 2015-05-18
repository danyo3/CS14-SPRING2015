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
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


int nummoves;
template<typename L>
void selectionsort(L &l)
{
    typename L::iterator it = l.begin();
    for(it = l.begin(); it != l.end(); it++)
    {
        typename L::iterator it2 = it;
        typename L::iterator min_it = it;
        
        for (it2++; it2 != l.end(); it2++)
        {
            if (*it2 < *min_it)
            {
                min_it = it2;
            }
        }
        if (*min_it != *it)
        {
            // cout << "swap" << endl;
            swap(*min_it, *it);
        }
    }
}
