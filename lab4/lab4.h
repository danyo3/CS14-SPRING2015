//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Danny Diep <ddiep003>
// SID: 861146918
// Date: May 4, 2015
// Lab 4
//  ================== END ASSESSMENT HEADER ===============

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
using namespace std;



void printPreorder(int m, int n, const int k)
{
    if (m + n >= k)
    {
        return;
    }
    else
    {
        cout << m << " " << n << endl;
    }
    
    printPreorder( 2 * m - n , m , k ); //left
    printPreorder(2 * m + n , m , k); //middle
    printPreorder( m + 2 * n , n , k ); //right
}    
void preorder(const int k)
{
    //cout << "K: " << k << endl;
    printPreorder(2, 1, k);
    printPreorder(3, 1, k);
    //printPreorder(3, 1, k);
}

void printPostorder( int m, int n, const int k)
{
    if (m + n >= k)
    {
        return;
    }
    printPostorder( 2 * m - n , m , k ); //left
    printPostorder(2 * m + n , m , k); //middle
    printPostorder( m + 2 * n , n , k ); //right
    if ( m + n < k)
    {
        cout << m << " " << n << endl;
    }
}

void postorder(const int k)
{
    //cout << "K: " << k << endl;
    printPostorder(2,1,k);
    printPostorder(3,1,k);
}
void printsortedorder(int m, int n, const int k, int t, priority_queue <pair <int, int> > & Pqueue )
{
    
    pair <int, int> temp(m,n);
    if (temp.first + temp.second >= k)
    {
        return;
    }
    if (temp.first + temp.second == t )
    {
        Pqueue.push(temp);
    }
    printsortedorder( 2 * m - n , m , k, t, Pqueue ); //left
    printsortedorder(2 * m + n , m , k, t, Pqueue); //middle
    printsortedorder( m + 2 * n , n , k, t, Pqueue ); //right
    while (!Pqueue.empty())
    {
        cout << Pqueue.top().first << " " << Pqueue.top().second << endl;
        Pqueue.pop();
    }
}
void sortedorder(const int k)
{
    
    //cout << "K: " << k << endl;
    priority_queue <pair<int, int> > PQ;
    for (int i = 3; i < k; i++) //i = 3 because thats the lowest sum it can get
    {
        printsortedorder(2, 1, k, i, PQ);
        printsortedorder(3, 1, k, i, PQ);
    }
    
}
