#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include "lab5.h"
using namespace std;

int main()
{
    BST <int> tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(40);
    tree.insert(70);
    tree.insert(35);
    tree.insert(45);
    cout << "Part1: \n";
    tree.displayMinCover();
    return 0;
}