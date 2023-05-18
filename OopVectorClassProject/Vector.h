#pragma once
#include <exception>
#include <stdexcept>
#include "IIterator.h"

template <typename T>
class Vector
{
	int size;
	int capacity;
	T* items;

	void capacityAdd();
	void capacityDel();
public:
	Vector();
	Vector(int size);
	
	Vector(const Vector<T>& v);
	Vector(Vector<T>&& v) noexcept;

	Vector(T array[], int size);

	T& operator[](int index);
	T& At(int index);

	int Size();

	VectorIterator<T>* GetIterator();

	void PushBack(T value);
	T PopBack();

	void Insert(T value, int index);
	T Remove(int index);

	~Vector();
};


template<typename T>
inline void Vector<T>::capacityAdd()
{
	capacity += capacity / 2;
	T* itemsNew = new T[capacity];
	for (int i = 0; i < size; i++)
		itemsNew[i] = items[i];

	delete[] items;
	items = itemsNew;
}

template<typename T>
inline void Vector<T>::capacityDel()
{
	capacity -= size / 2;
	T* itemsNew = new T[capacity];

	for (int i = 0; i < size; i++)
		itemsNew[i] = items[i];
	delete[] items;
	items = itemsNew;
}

template<typename T>
inline Vector<T>::Vector()
{
	capacity = 2;
	size = 0;
	items = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(int size)
	: size{ size },
	capacity{ size + size / 2 },
	items{ new T[capacity] } {}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& v)
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->items = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->items[i] = v.items[i];
}

template<typename T>
inline Vector<T>::Vector(Vector<T>&& v) noexcept
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->items = v.items;

	v.items = nullptr;
}

template<typename T>
inline Vector<T>::Vector(T array[], int size)
	: size{ size },
	capacity{ size + size / 2 },
	items{ new T[capacity] }
{
	for (int i = 0; i < this->size; i++)
		this->items[i] = array[i];
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	return items[index];
}

template<typename T>
T& Vector<T>::At(int index)
{
	if (index < 0 || index > this->size)
		throw new std::out_of_range("invalid index of vector");
	return items[index];
}

template<typename T>
int Vector<T>::Size()
{
	return this->size;
}

template<typename T>
VectorIterator<T>* Vector<T>::GetIterator()
{
	return new VectorIterator<T>(this);
}

template<typename T>
inline void Vector<T>::PushBack(T value)
{
	if (this->size >= this->capacity)
		capacityAdd();
	
	items[size++] = value;
}

template<typename T>
inline T Vector<T>::PopBack()
{
	T value = items[--size];

	if (capacity > size + size * 2)
		capacityDel();

	return value;
}

template<typename T>
inline void Vector<T>::Insert(T value, int index)
{
	if (size >= capacity)
		capacityAdd();

	for (int i = size - 1; i >= index; i--)
		items[i + 1] = items[i];
	items[index] = value;
	size++;
}

template<typename T>
inline T Vector<T>::Remove(int index)
{
	T value = items[index];

	for (int i = index; i < size; i++)
		items[i] = items[i + 1];
	size--;

	if (capacity > size + size / 2)
		capacityDel();

	return value;
}

template<typename T>
Vector<T>::~Vector()
{
	if (this->items)
		delete[] this->items;
}

