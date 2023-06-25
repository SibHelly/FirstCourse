#include <iostream>
#include "FunctionsRead.cpp"
#include "FunctionsForList.cpp"
#include <memory.h>
#include <limits>
#include "spisok.h"
using namespace std;

int main()
{
    Graf x(5);
    x.addVert(0, 1);
    x.addVert(0, 2);
    x.addVert(1, 4);
    x.addVert(3, 4);
    x.showGraf();
}