#include <iostream>
#include "Vector.h"

int main()
{
    srand(time(nullptr));

    Vector<int> vInt(10);
    for (int i = 0; i < vInt.Size(); i++)
        vInt[i] = rand() % 100;

    VectorIterator<int>* it = vInt.GetIterator();

    for(it->Set(); !it->IsEnd(); it->Next())
        std::cout << it->Current() << " ";
    
    
}
