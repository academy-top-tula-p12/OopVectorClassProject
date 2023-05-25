#include <iostream>
#include "Vector.h"
#include "Stack.h"

int main()
{
    /*
    srand(time(nullptr));

    Vector<int> vInt(10);
    for (int i = 0; i < vInt.Size(); i++)
        vInt[i] = rand() % 100;

    VectorIterator<int>* it = vInt.GetIterator();

    for(it->Set(); !it->IsEnd(); it->Next())
        std::cout << it->Current() << " ";
    */

    Stack<int> stack;
    stack.Push(100);
    stack.Push(200);
    stack.Push(300);

    stack.Print();

    std::cout << stack.Pop() << "\n\n";

    stack.Print();
    
}
