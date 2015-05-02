//Name: Danny Diep
//SID: 861146918
//Date: 4-16-20-15
#include "lab2.h"
#include <forward_list>
bool isPrime(int i) 
    {
    if (i <= 3) {
        return i > 1;
    }
 
    if (i % 2 == 0 || i % 3 == 0) {
        return false;
    }
 
    for (int j = 5; j * j <= i; j += 6) 
    {
        if (i % j == 0 || i % (j + 2) == 0) 
        {
            return false;
        }
    }
 
    return true;
    }

int primeCount(forward_list<int> lst)
{
    if (lst.begin() == lst.end())
    {
        return 0;
    }
    else if (isPrime(*lst.begin()) == true)
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    lst.pop_front();
    return primeCount(lst);
}




