#pragma once
#include <iostream>
#include "Vector.h"

template <typename T>
class Stack
{
	Vector<T> stack;
	int head;
public:
	Stack() : head{ -1 } {}
	void Push(T value);
	T Pop();
	T Peek();

	void Print();
};

template<typename T>
inline void Stack<T>::Push(T value)
{
	stack.PushBack(value);
	head++;
}

template<typename T>
inline T Stack<T>::Pop()
{
	head--;
	return stack.PopBack();
}

template<typename T>
inline T Stack<T>::Peek()
{
	return stack.At(head);
}

template<typename T>
inline void Stack<T>::Print()
{
	for (int i = head; i >= 0; i--)
		std::cout << stack.At(i) << "\n";
	std::cout << "\n";
}


